#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include "functions.h"

void curve(double x1, double y1, double x2, double y2, int rec) {
	double dx, dy;
	double x3, y3, x4, y4, x5, y5;


	if (rec == 0) {
		line(floor(x1 + 0.5), floor(y1 + 0.5), floor(x2 + 0.5), floor(y2 + 0.5));
		return;

	}

	dx = x2 - x1;
	dy = y2 - y1;

	x3 = x1 + dx/3;
	y3 = y1 + dy/3;

	x4 = x2 - dx/3;
	y4 = y2 - dy/3;

	x5 = x3 + ((x4 - x3) + (y4 - y3)*sqrt(3))*0.5;
	y5 = y3 + ((y4 - y3) + (x4 - x3)*sqrt(3))*0.5;

	curve(x1, y1, x3, y3, rec - 1);
	curve(x3, y3, x5, y5, rec - 1);
	curve(x5, y5, x4, y4, rec - 1);
	curve(x4, y4, x2, y2, rec - 1);
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int rec) {
	if (rec) {
		int points[] = {floor((x1 + x2)/2 + 0.5), floor((y1 + y2)/2 + 0.5),
				floor((x2 + x3)/2 + 0.5), floor((y2 + y3)/2 + 0.5),
				floor((x1 + x3)/2 + 0.5), floor((y1 + y3)/2 + 0.5)};
		fillpoly(3, points);

		triangle(x1, y1, (x1 + x2)/2, (y1 + y2)/2, (x1 + x3)/2, (y1 + y3)/2, rec - 1);

		triangle((x1 + x2)/2, (y1 + y2)/2, x2, y2, (x2 + x3)/2, (y2 + y3)/2, rec - 1);

		triangle((x1 + x3)/2, (y1 + y3)/2, (x2 + x3)/2, (y2 + y3)/2, x3, y3, rec - 1);
	}
}


void carpet(double x1, double y1, double x2, double y2, int rec) {
	double n_x1, n_y1, n_x2, n_y2;
	if (rec) {
		n_x1 = 2*x1/3 + x2/3;
		n_x2 = x1/3 + 2*x2/3;
		n_y1 = 2*y1/3 + y2/3;
		n_y2 = y1/3 + 2*y2/3;

		bar(n_x1, n_y1, n_x2, n_y2);

		carpet(x1, y1, n_x1, n_y1, rec - 1);
		carpet(n_x1, y1, n_x2, n_y1, rec - 1);
		carpet(n_x2, y1, x2, n_y1, rec - 1);
		carpet(x1, n_y1, n_x1, n_y2, rec - 1);
		carpet(n_x2, n_y1, x2, n_y2, rec - 1);
		carpet(x1, n_y2, n_x1, y2, rec - 1);
		carpet(n_x1, n_y2, n_x2, y2, rec - 1);
		carpet(n_x2, n_y2, x2, y2, rec - 1);
	}
}
