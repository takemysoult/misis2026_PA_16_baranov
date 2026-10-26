#include <iostream>
#include "header.h"
using namespace std;

int main() {
    cout << "LAB 2. MULTI-FILE PROJECTS\n\n";

    cout << "1. Distance between points\n";
    cout << "Distance((0,0),(3,4)) = " << Distance(0, 0, 3, 4)
         << " (expected 5)\n";
    cout << "Distance((1,1),(1,1)) = " << Distance(1, 1, 1, 1)
         << " (expected 0)\n\n";

    cout << "2. Triangle area\n";
    cout << "Square((0,0),(4,0),(0,3)) = " << Square(0, 0, 4, 0, 0, 3)
         << " (expected 6)\n";
    cout << "Square((0,0),(1,1),(2,2)) = " << Square(0, 0, 1, 1, 2, 2)
         << " (expected 0 for collinear points)\n\n";

    cout << "3. Distance from point to line\n";
    cout << "Distance from (0,3) to line through (0,0),(4,0) = "
         << Distance_to_line(0, 3, 0, 0, 4, 0) << " (expected 3)\n";
    cout << "Degenerate line through (1,1),(1,1) returns "
         << Distance_to_line(0, 0, 1, 1, 1, 1) << " (-1 means invalid line)\n\n";

    cout << "4. Triangle classification (additional tasks)\n";
    cout << "(0,0),(3,0),(0,4) type = "
         << Check_triangle_type(0, 0, 3, 0, 0, 4) << " (0 means arbitrary)\n";
    cout << "(0,0),(2,0),(1,1.7320508075688772) type = "
         << static_cast<int>(Check_triangle_type_new(0, 0, 2, 0, 1, 1.7320508075688772))
         << " (2 means equilateral)\n";
    cout << "(0,0),(4,0),(2,5) type = "
         << Check_triangle_type(0, 0, 4, 0, 2, 5) << " (1 means isosceles)\n";
    cout << "(0,0),(1,1),(2,2) type = "
         << Check_triangle_type(0, 0, 1, 1, 2, 2) << " (-1 means points do not form a triangle)\n";
    cout << "(1,1),(1,1),(3,2) type = "
         << static_cast<int>(Check_triangle_type_new(1, 1, 1, 1, 3, 2))
         << " (-1 means points do not form a triangle)\n\n";

    cout << "5. Overload using point structure\n";
    point a = {0, 0};
    point b = {3, 4};
    cout << "Distance(point a, point b) = " << Distance(a, b) << " (expected 5)\n";
    point c = {0, 4};
    cout << "Right triangle type with point arguments = "
         << static_cast<int>(Check_triangle_type_new(a, b, c))
         << " (0 means arbitrary)\n";

    return 0;
}
