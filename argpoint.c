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