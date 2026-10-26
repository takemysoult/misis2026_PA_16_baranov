#ifndef LAB2_HEADER_H
#define LAB2_HEADER_H


// расстояние между точками (x1, y1) и (x2, y2)
double Distance(double x1, double y1, double x2, double y2);


// площадь треугольника по координатам вершин
double Square(double xa, double ya, double xb, double yb, double xc, double yc);


// расстояние от точки (xa, ya) до прямой через (x1, y1) и (x2, y2)
// если точки прямой совпадают, то возвращает -1
double Distance_to_line(double xa, double ya,
                        double x1, double y1, double x2, double y2);


struct point {
    double x;
    double y;
};
double Distance(point a, point b);


enum triangle_type {
    tInvalid = -1,
    tArbitrary = 0,
    tIsoscel = 1,
    tEqui = 2
};

// 2 - равносторонний, 1 - равнобедренный, 0 - произвольный, -1 - не треугольник
int Check_triangle_type(double xa, double ya, double xb, double yb, double xc, double yc);
// перегрузить по типу результата нельзя, поэтому другое имя
triangle_type Check_triangle_type_new(double xa, double ya, double xb, double yb, double xc, double yc);
triangle_type Check_triangle_type_new(point a, point b, point c);

#endif
