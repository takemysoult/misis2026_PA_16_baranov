#ifndef LAB2_HEADER_H
#define LAB2_HEADER_H


double Distance(double x1, double y1, double x2, double y2);


double Square(double xa, double ya, double xb, double yb, double xc, double yc);



double Distance_to_line(double xa, double ya,
                        double x1, double y1, double x2, double y2);


struct point {
    double x;
    double y;
};
double Distance(point a, point b);


enum triangle_type {
    tArbitrary = 0, 
    tIsoscel = 1,   
    tEqui = 2       
};

int Check_triangle_type(double xa, double ya, double xb, double yb, double xc, double yc);
triangle_type Check_triangle_type_new(double xa, double ya, double xb, double yb, double xc, double yc);
triangle_type Check_triangle_type_new(point a, point b, point c);

#endif
