#include "header.h"

namespace {
    double absoluteValue(double value) {
        return value < 0.0 ? -value : value;
    }

    
    double squareRoot(double value) {
        if (value < 0.0) return -1.0;
        if (value == 0.0) return 0.0;
        double guess = value >= 1.0 ? value : 1.0;
        for (int i = 0; i < 100; ++i) {
            double next = (guess + value / guess) / 2.0;
            if (absoluteValue(next - guess) < 1e-12) return next;
            guess = next;
        }
        return guess;
    }
}

double Distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return squareRoot(dx * dx + dy * dy);
}

double Square(double xa, double ya, double xb, double yb, double xc, double yc) {
    
    double determinant = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
    return absoluteValue(determinant) / 2.0;
}

double Distance_to_line(double xa, double ya,
                        double x1, double y1, double x2, double y2) {
    double lineLength = Distance(x1, y1, x2, y2);
    if (lineLength == 0.0) return -1.0;
    double numerator = absoluteValue((x2 - x1) * (y1 - ya) -
                                     (x1 - xa) * (y2 - y1));
    return numerator / lineLength;
}

double Distance(point a, point b) {
    return Distance(a.x, a.y, b.x, b.y);
}


int Check_triangle_type(double xa, double ya, double xb, double yb, double xc, double yc) {
    double ab = Distance(xa, ya, xb, yb);
    double bc = Distance(xb, yb, xc, yc);
    double ca = Distance(xc, yc, xa, ya);
    const double tolerance = 1e-9;
    if (ab == 0.0 || bc == 0.0 || ca == 0.0 ||
        ab + bc <= ca || ab + ca <= bc || bc + ca <= ab) return 0;
    bool ab_eq_bc = absoluteValue(ab - bc) < tolerance;
    bool bc_eq_ca = absoluteValue(bc - ca) < tolerance;
    bool ca_eq_ab = absoluteValue(ca - ab) < tolerance;
    if (ab_eq_bc && bc_eq_ca) return 2;
    if (ab_eq_bc || bc_eq_ca || ca_eq_ab) return 1;
    return 0;
}

triangle_type Check_triangle_type_new(double xa, double ya, double xb, double yb, double xc, double yc) {
    return static_cast<triangle_type>(Check_triangle_type(xa, ya, xb, yb, xc, yc));
}

triangle_type Check_triangle_type_new(point a, point b, point c) {
    return Check_triangle_type_new(a.x, a.y, b.x, b.y, c.x, c.y);
}
