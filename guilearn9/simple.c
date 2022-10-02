#include <u.h>
#include <libc.h>
#include <draw.h>
#include <cursor.h>
#include <thread.h>
#include <mouse.h>
#include <keyboard.h>

void
threadmain(int argc, char *argv[])
{
	ulong co; // a color
	Image *im1, *im2, *bg; // pointers for image1, image2, background
	Mousectl *mctl;
	Keyboardctl *kctl;
	Mouse mouse;
	int resize[2];
	Rune kbd;
	uchar magenta[3] = {0xFF, 0x00, 0xFF};
	uchar cyan[3] = {0xFF, 0xFF, 0x00};
	uchar purple[3] = {0xFF, 0x00, 0xA0};
	uchar orange[3] = {0x00, 0x7F, 0xFF};
	
	co = 0xFF0000FF;; //RGB Red and Opaque

	ARGBEGIN{
	case 'b':
		co = DBlue;
	default:
		fprint(2, "usage: %s [-b]\n", argv0);
		exits("usage");
	}ARGEND;

	if(initdraw(nil, nil, argv0) < 0)
		sysfatal("%s: %r", argv0);
	im1 = allocimage(display, Rect(0,0,100,100), RGB24, 0, DYellow);
	im2 = allocimage(display, Rect(0,0,100,100), RGBA32, 0, 0x007F007F);
	bg = allocimage(display, Rect(0,0,1,1), RGB24, 1, co);
	if(im1 == nil || im2 == nil || bg == nil)
		sysfatal("get more memory, bub");
	draw(screen, screen->r, bg, nil, ZP);
	draw(screen, screen->r, im1, nil, Pt(-40,-40));
	draw(screen, screen->r, im2, nil, Pt(-20,-20));
	flushimage(display, Refnone);
	
	if((mctl = initmouse(nil, screen)) == nil)
 		sysfatal("%s: %r", argv0);
	if((kctl = initkeyboard(nil)) == nil)
		sysfatal("%s: %r", argv0);

	enum{MOUSE, RESIZE, KEYBD, NONE};
	Alt alts[4] = {
		{mctl->c, &mouse, CHANRCV},
		{mctl->resizec, &resize, CHANRCV},
		{kctl->c, &kbd, CHANRCV},
		{nil, nil, CHANEND},
	};

	for(;;) {
		switch(alt(alts)) {

		case MOUSE:
			if(mouse.buttons == 1)
				loadimage(bg, bg->r, magenta, sizeof(magenta));
			else if(mouse.buttons == 4)
				loadimage(bg, bg->r, cyan, sizeof(cyan));
			draw(screen, screen->r, bg, nil, ZP);
			draw(screen, screen->r, im1, nil, Pt(-40,-40));
			draw(screen, screen->r, im2, nil, Pt(-20,-20));
			flushimage(display, Refnone);
			break;

		case RESIZE:
			if(getwindow(display, Refnone) < 0)
				sysfatal("%s: %r", argv0);
			draw(screen, screen->r, bg, nil, ZP);
			draw(screen, screen->r, im1, nil, Pt(-40,-40));
			draw(screen, screen->r, im2, nil, Pt(-20,-20));
			flushimage(display, Refnone);
			break;

		case KEYBD:
			if(kbd == 'a')
				loadimage(bg, bg->r, purple, sizeof(purple));
			else if(kbd == 'b')
				loadimage(bg, bg->r, orange, sizeof(orange));
			else if(kbd == 'q')
				threadexitsall(nil);
			draw(screen, screen->r, bg, nil, ZP);
			draw(screen, screen->r, im1, nil, Pt(-40,-40));
			draw(screen, screen->r, im2, nil, Pt(-20,-20));
			flushimage(display, Refnone);
			break;

		case NONE:
			break;
		}
	}
}