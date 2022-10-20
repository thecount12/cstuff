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
