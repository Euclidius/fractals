#include <stdio.h>
#include <graphics.h>
#include "functions.h"



int main() {
    int type = 1;
    int rec = 3;
	int gd = DETECT, gm = DETECT;


	initgraph(&gd, &gm, "");
	switch (type) {
		case 1:
			bar(0, 0, 640, 480);
			if (rec) {
				carpet(90, 10, 550, 470, rec);
			}
			break;
		case 2:
			bar (0, 0, 640, 480);
			if (rec) {
				triangle(10, 470, 320, 10, 630, 470, rec);
			}
			break;
		case 3:
			bar(0, 0, 640, 480);
			if (rec) {
				curve(10, 330, 630, 330, rec);
			}
			break;
		default:
			puts("alarm alarm achtung!!!!!!");
			return 1;

	}

	while (1) {
        int c = readkey();

        if (c == 72 && rec < 5) {
            clearviewport();

            switch (type) {
                case 1:
                    carpet(90, 10, 550, 470, ++rec);
                    break;
                case 2:
                    triangle(10, 470, 320, 10, 630, 470, ++rec);
                    break;
                case 3:
                    curve(10, 330, 630, 330, ++rec);
                    break;
            }
        }
        if (c == 80 && rec) {
            clearviewport();

            switch (type) {
                case 1:
                    carpet(90, 10, 550, 470, --rec);
                    break;
                case 2:
                    triangle(10, 470, 320, 10, 630, 470, --rec);
                    break;
                case 3:
                    curve(10, 330, 630, 330, --rec);
                    break;
            }
        }
    }
}
