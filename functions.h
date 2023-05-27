#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void carpet(double a, double b, double c, double d, int rec);
void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int rec);
void curve(double x1, double y1, double x2, double y2, int rec);

void show_carpet(double x1, double y1, double x2, double y2, int rec);
void show_triangle(double x1, double y1, double x2, double y2, double x3, double y3, int rec);
void show_snowflake(double x1, double y1, double x2, double y2, int rec);

#endif //FUNCTIONS_H_INCLUDED
