# Plan9 and C programming

These are sure to be very small chapters in my experience messing around with plan9 
programming. 


## Chapter 1 First

	; touch first.c
	; acme first.c # or use sam below
	; sam first.c

Type in the following code

	#include <u.h>
	#include <libc.h>

	void
	main(int, char*[])
	{
		print("Welcome to C on Plan9!\n");
		exits(nil);
	}

A few things are different such as void being on its own line above the main() function
Headers are different most programs need 'u.h' or 'libc.h' 

You will wan to run the following commands to compile your programs

	; 8c first.c	# compile it
	; 8l first.8	# link the object

On arm64 you would use

	; 7c first.c		# compile
	; 7l first.7 	# link the object

Now you can run the program

	; 7.out
	Welcome to C on Plan9!

The Plan9 C dialect is not ANSI or ISO C. It is a variation implemented by Ken Thompson.

You can use additional flags for more strict features. 

	; 7c -FVw first.c
	; 7l first.7

The files generated in the directory are as follows: 

	; ls -l
	--rwxrwxr-x M 24 glenda glenda 34926 Aug 12 00:28 7.out
	--rwxrwxr-x M 24 glenda glenda 34926 Aug 12 00:33 first
	--rw-rw-r-- M 24 glenda glenda   539 Aug 12 00:27 first.7
	--rw-rw-r-- M 24 glenda glenda   111 Aug 12 06:51 first.c

We can also give it a better name

	; 7l -o first first.7

This creates a file called: first


The file created is about 111 bytes. Nice and small. But once you create the oject and link it
you get the final executable. 

You can look deeper into the files:

	; nm first.7
 	U exits
 	T main
 	U print
	
	; nm 7.out
   	14030 L Inf
   	13fb8 L NaN
   	11984 T _badfmt
   	149d0 L _barrier...

You have a procdure called main in first.7. T are the text contained in the object. U is print as
implied by the statement that follows it. There is a bunch of proeceudres call or system call's
beyond scope of this document but you can research that later. 


## Argument input

readargs.c

	#include <u.h>
	#include <libc.h>

	void
	main(int argc, char* argv[])
	{
		int i;
		for (i=0; i < argc; i++)
			print("%d: %s\n", i, argv[i]);
		exits(nil);
	}

Now compile and execute the program

	; 7c -FVw readargs.c 
	; 7l -o readargs readargs.7

Enter some arguments as follows:

	; readargs how are you
	0: readargs
	1: how
	2: are
	3: you
	;

## Flags and switches

	#include <u.h>
	#include <libc.h>
	
	void
	main(int argc, char* argv[])
	{
		int nf = 0;
		int vf = 0;
		int i;
		
		ARGBEGIN{
		case 'v':
				vf = 1;
				print("hit the v=%d flag\n", vf);
				break;
		case 'n':
				nf = 1;
				print("hit the n=%d flag\n", nf);
				break;
		default:
				fprint(2, "usage: %s [-nv] args\n", argv0);
				exits("usage");
		}ARGEND;
	
		for (i = 0; i < argc; i++)
			if (vf)
				print("[%s] ", argv[i]);
			else
				print("%s \n", argv[i]);
		if (!nf)
			print("\n");
		exits(nil);
	}

The compilation for this had errors with usage

	; 7c -FVw switchargs.c
	; 7l -o swargs switchargs.7

Not really sure why I got the errors because they are used in the case block, and
int the for loop. I can only assume scope issues. 

The madcros ARGBEGIN and ARGEND loop through the arg processing. 

	; swargs -n foo bar
	hit the n=1 flag
	foo 
	bar 
	; swargs -v foo bar
	hit the v=1 flag
	[foo] [bar] 
	; swargs -l foo bar
	usage: swargs [-nv] args

## Pointers and ARGF

	#include <u.h>
	#include <libc.h>
	
	void
	usage(void)
	{
		fprint(2, "usage: %s [-nv] [-d delims] args\n", argv0);
		exits("usage");
	}
	void
	main(int argc, char* argv[])
	{
		int nf = 0;
		int vf = 0;
		char* delims = "[]";
		int i;
	
		ARGBEGIN{
		case 'v':
			vf = 1;
			break;
		case 'n':
			nf = 1;
			break;
		case 'd':
			delims = ARGF();
			if (delims == nil || strlen(delims) < 2)
				usage();
			break;
		default:
			usage();
		}ARGEND;
	
		for (i = 0; i < argc; i++)
		if (vf)
			print("%c%s%c ", delims[0], argv[i], delims[1]);
		else
			print("%s ", argv[i]);
		if (!nf)
			print("\n");
		exits(nil);

	}

Compile the program as follows: 

	; 7c -FVw argpoint.c
	; 7l -o argpt argpoint.7

Test out the results below:

	; argpt -n foo bar
	foo bar ; argpt -v foo bar
	[foo] [bar] 
	; argpt -d foo bar
	bar 
	; argpt -l foo bar
	usage: argpt [-nv] [-d delims] args
	; argpt -v -d foo bar
	fbaro 
	; argpt -v -d , foo
	usage: argpt [-nv] [-d delims] args
	; argpt -- -d repeate after me
	-d repeate after me 
	; argpt -d repeat after me
	after me 
	; argpt -v -d"" repeate after me
	"repeate" "after" "me" 
	; argpt -vd "" repeat after me
	"repeat" "after" "me" 


## System Errors

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* [])
	{
		DIR *d;
		struct dirent 
		
		if (chdir("magic") < 0) {
			fprint(2, "chdir failed: %r\n");
			exits("failed");
		}
		print("interesting");
		exits(nil);
	}

Compile and execute:

	; 7c -FVw err.c
	: 7l -o myerr err.7

Run the program

	; myerr
	chdir failed: 'magic' not found

## Environement Variables

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char*[])
	{
		char* home;
		home = getenv("home");
		if (home == nil)
			sysfatal("we are not here");
		print("home is %s\n", home);
		exits(nil);
	}

compile it:

	; 7c -FVw env.c
	; 7l -o 7.env env.7

In this case I named the file 7.env. By convention in plan9 you shoul name
the files after the archetecture in which it is compiled for. 

Run it: 

	; 7.env
	home is /usr/glenda

### Tracking Process ID's

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* [])
	{
		int pid;
		pid = getpid();
		print("my pid is %d\n", pid);
		exits(nil);
	}

compile the program 

	; 7c -FVw pid.c
	; 7l -o 7.pid pid.7

Run it a couple of times

	; 7.pid
	my pid is 10078
	; term% 7.pid
	my pid is 10080

### Debugging 

create debughi.c

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char*argv[])
	{
		/* lets create a problem */
		print("hi ");
		print(argv[1]);
		exits(nil);
	}

Lets compile this

	; 7.debug
	hi 7.debug 5128: suicide: sys: trap: fault read addr=0x0 pc=0x103e0
	; 7.debug asdf
	hi asdf 

The first time we run it it has an error

You can check sthat status of the execution

	; echo $status
	7.debug 5171: sys: trap: fault read addr=0x0 pc=0x103e0

The program src knows how to extract line number of the programs problem

	; src -n -s 0x103e0 7.debug
	/sys/src/libc/fmt/dofmt.c:37

We can look at the process ide 

	;ps 
	...
	glenda         5171    0:00   0:00      192K Broken   7.debug
	
we can trace through the debugger using acid

	; acid 5171
	/proc/5171/text:arm64 plan 9 executable
	/sys/lib/acid/port
	/sys/lib/acid/arm64
	acid:

Inside the debuger type stk()

	acid: stk()
	dofmt(fmt=0x0,f=0x1fffefe68)+0x184 /sys/src/libc/fmt/dofmt.c:37
	vfprint(args=0x1fffefef8,fmt=0x0)+0x38 /sys/src/libc/fmt/vfprint.c:30
	print(fmt=0x0)+0x20 /sys/src/libc/fmt/print.c:11
	main(argv=0x1fffeffa0)+0x10 /usr/glenda/code/cstuff/debughi.c:9
	_main+0x28 /sys/src/libc/arm64/main9.s:17

The program crashed executing dofmt at dofmt.c and that was called by vfprint, which
was called by print, which was called by main. We can gather more information 
using lstk().

	dofmt(fmt=0x0,f=0x1fffefe68)+0x184 /sys/src/libc/fmt/dofmt.c:37
		nfmt=0x0
		rt=0x0
		rs=0x3
		r=0x300000001
		rune=0x100e400000003
		t=0x1fffefd68
		s=0x1fffefe68
		n=0xfffefe6800000000
	vfprint(args=0x1fffefef8,fmt=0x0)+0x38 /sys/src/libc/fmt/vfprint.c:30
		f=0x0
		buf=0x206968
		n=0x20696800000003
	print(fmt=0x0)+0x20 /sys/src/libc/fmt/print.c:11
		args=0x1fffefef8
	main(argv=0x1fffeffa0)+0x10 /usr/glenda/code/cstuff/debughi.c:9
	_main+0x28 /sys/src/libc/arm64/main9.s:17


### Abort

I'm not exactly sure how to use this but we can look at it later

void
abort(void)
{
	while(*(int*)0);
}


### Everything is a file in plan9

Lets look at time

	; ls -l /dev/time
	--rw-rw-r-- c 0 glenda glenda 78 Aug 31 00:53 /dev/time
	; cat /dev/time
 	1662269290   1662269290529058457  201274132734  8333404

So while file is zero in size it still exists. The system recognize cat on a file 
location and populates data for stdout representation.

/proc file system is the same. It does not exist on disk but its an interface for 
data representation and you can make changnes when you 'echo' new values to the files.
 
### Files

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* [])
	{
		char msg[] = "hello\n";
		int ltem;
		item = strlen(msg);
		write(l, msg, item);
		exits(nil);
	}

	;7c -FVw write.c
	;7l -o 7.write write.7
	hello


Now lets read file or buffer

#include <u.h>
#include <libc.h>

void
main(int, char* [])
{
	char buffer[1024];
	int nr;

	nr = read(0, buffer, sizeof buffer);
	write(1, buffer, nr);
	exits(nil);

}

	;7c -FVw read.c
	;7l -o 7.read read.7
	;7.read
	cool
	cool

### Write to files

first echo "asdfas" > afile

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* [])
	{
		char msg[] = "hello\n";
		int fd;
		fd = open("/usr/glenda/code/cstuff/afile", OWRITE);
		write(fd, msg, strlen(msg));
		close(fd);
		exits(nil);
	}

Compile and run the file

	; 7c -FVw writefile.c
	; 7l -o 7.writef writefile.7
	; 7.writef

	;xd -c afile
	xd -c afile
	0000000   h  e  l  l  o \n  s  d  f  a  s  " \n
	000000d 


you can add more data and seek a postion to place the message

	fd = open("afile", OWRITE):
	seek(fd, 10, 0);
	write(fd, "hello\n", 6);
	close(fd);

Trucate

	fd = open("afile", OWRITE|OTRUNC):

### reading from files

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* []) 
	{
		char buffer[10];
		int nr;
		int fd;
	
		fd = open("/usr/glenda/code/cstuff/afile", OREAD);
		if (fd < 0)
			sysfatal("open: %r");
		for(;;) {
			nr = read(fd, buffer, sizeof buffer);
			if (nr <= 0);
				break;
			if (write(1, buffer, nr) != nr);
				sysfatal("write: %r");
		}
		exits(nil);
	}

	; 7c -FVw readf.c
	; 7l -o 7.readf readf.7


### creating and removing files

	#include <u.h>
	#include <libc.h>
	
	void
	main(int, char* [])
	{
		int fd;
		char msg[] = "a new file\n";
		fd = create("afile", OWRITE, 0664);
		write(fd, msg, strlen(msg));
		close(fd);
		exits(nil);
	}

You can remove the previous or this will over write.

	; 7c -FVw create.c
	; 7l -o 7.create create.7

### Remove files

	#include <u.h>
	#include <libc.h>
	
	void
	main(int argc, char* argv[])
	{
		int i;
		for (i = 1; i < argc; i++)
			if (remove(argv[i]) < 0)
				fprint(2, "%s: %r\n", argv[0]);
		exits(nil);
	}

	; 7c -FVw rm.c
	; 7l -o 7.rm rm.7

If a file does not exist

	; 7c -FVw rm.c
	; 7l -o 7.rm rm.7

You should test first

	if (access(fname, AEXIST) < 0)
		sysfatal("%s does not exisaat", fname);


I ended up on pager 79 Parent and Child

I skipped a few things regarding listing directories and
more buffer stuff and some binary copy stuff. 

