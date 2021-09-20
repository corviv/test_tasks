#include "Point.h"

Point::Point(double Px, double Py) : x(Px), y(Py) {}

bool Point::operator==(const Point &a) const {
    if (a.x == x && a.y == y) {
        return true;
    }
    return false;
}

bool Point::operator<(const Point &a) const {
    if (x < a.x || y < a.y) {
        return true;
    }
    return false;
}
