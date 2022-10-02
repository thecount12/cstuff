/* grade my gradient from 0 to nein */
#include <u.h>
#include <libc.h>
#include <draw.h>
void
main(int argc, char *argv[])
{	ARGBEGIN{
    default:
	fprint(2, "usage: %s [-b]\n", argv0);
    exits("usage");
   	}ARGEND;
    if(initdraw(nil, nil, argv0) < 0)
		sysfatal("%s: %r", argv0);
	Image *red, *grn, *blu, *gradx, *grady;
  	int dx, dy, i;
  	uchar *gx, *gy;
   	red = allocimage(display, Rect(0,0,1,1), RGB24, 1, DRed);
  	grn = allocimage(display, Rect(0,0,1,1), RGB24, 1, DGreen);
  	blu = allocimage(display, Rect(0,0,1,1), RGB24, 1, DBlue);
  	dx = Dx(screen->r), dy = Dy(screen->r);
  	gradx = allocimage(display, Rect(0,0,dx,1), GREY8, 1, DNofill);
  	grady = allocimage(display, Rect(0,0,1,dy), GREY8, 1, DNofill);
   	gx = malloc(sizeof(uchar) * dx);
  	gy = malloc(sizeof(uchar) * dy);
  	if(red == nil || grn == nil || blu == nil || gradx == nil || grady == nil || gx == nil || gy == nil)
  		sysfatal("get more memory dude");
  	for(i = 0; i < dx; i++)
      	gx[i] = (uchar)(255.0 * i / (dx-1)); /* sub 1 to make last row 255 */
  	for(i = 0; i < dy; i++)
    	gy[i] = (uchar)(255.0 * i / (dy-1));
  	loadimage(gradx, gradx->r, gx, dx);
 	loadimage(grady, grady->r, gy, dy);
 	draw(screen, screen->r, red, nil, ZP);
   	draw(screen, screen->r, grn, gradx, ZP);
  	draw(screen, screen->r, blu, grady, ZP);
  	flushimage(display, Refnone);
  	sleep(10000);
  	exits(nil);
}

