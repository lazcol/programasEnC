/**********************/
/* By. Dumitru Petrov */
/* Lab. 3 p.2 V21     */
/**********************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <graphics.h>
#include <X11/Xlib.h>

/*
**	Conversion of x coordinate - Window to Viewport
*/
double transformx(double coor, int *w)
{
	if (!w)
		return coor;
	return (((coor - w[0]) / (w[2] - w[0])) * (w[6] - w[4])) + w[4];
}
/*
**	Conversion of y coordinate - Window to Viewport
*/
double transformy(double coor, int *w)
{
	if (!w)
		return coor;
	return (((coor - w[1]) / (w[3] - w[1])) * (w[7] - w[5])) + w[5];
}

/*
**	draw "y = cos(k * x)" graphic
** 	if window parameter is null, then it is displayed on whole window
*/
void draw_second(int x_axis, int y_axis, double k, int *window)
{
	double x = -x_axis, y, px, py, cx = getmaxx()/2, cy = getmaxy()/2;

	while (x < x_axis) {
		/* Calculate y with given x */
		y = cos(k*x);
		
		/* Calculate coordoninates to display */
		px = x * cx / x_axis + cx;
		/* -cy because of origin point in window(top left corner) */
		py = y * -cy / y_axis + cy;
		if (px > getmaxx())
			break;

		if (x == -x_axis) // only for first loop
			moveto(transformx(px, window), transformy(py, window));
		/* Draw segment line */
		px = transformx(px, window);
		py = transformy(py, window);
		lineto(px, py);
		/* update CP */
		moveto(px, py);

		x += 0.01;
		//delay(2);
	}
}

void draw_axis(char *left, char *right, char *top, char *bottom, int w[])
{
	int xmax = getmaxx(), ymax = getmaxy();

	line(transformx(20, w), transformy(ymax/2, w), transformx(xmax-20, w), transformy(ymax/2, w));
	line(transformx(xmax/2, w), transformy(20, w), transformx(xmax/2, w), transformy(ymax-20, w));
	outtextxy(transformx(xmax/2, w),	transformy(ymax/2, w), "O");
	outtextxy(transformx(20, w),		transformy(ymax/2, w), left);
	outtextxy(transformx(xmax-40, w),	transformy(ymax/2, w), right);
	outtextxy(transformx(xmax/2, w),	transformy(20, w), top);
	outtextxy(transformx(xmax/2, w),	transformy(ymax-40, w), bottom);
}

int main()
{
	int gd = DETECT, gm;
 //   XInitThreads();	
	initgraph(&gd, &gm, NULL);

	/* draw axis */
	int window1[] = {0, 0, getmaxx(), getmaxy(), 0, 0, getmaxx()/2, getmaxy()/2};
	int window2[] = {0, 0, getmaxx(), getmaxy(), getmaxx()/2, 0, getmaxx(), getmaxy()/2};
	int window3[] = {0, 0, getmaxx(), getmaxy(), 0, getmaxy()/2, getmaxx(), getmaxy()};

	
	rectangle(getmaxx()/2, 0, getmaxx(), getmaxy()/2);

	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	rectangle(0, 0, getmaxx()/2, getmaxy()/2);

	draw_axis("-6", "6", "2", "-2", window1);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 2);
	draw_second(6, 2, 1, window1);

	getch();
	closegraph();
	return (0);
}