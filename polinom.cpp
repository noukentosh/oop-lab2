#include "polinom.h"

TPolinom::TPolinom (number x, number y, number z) {
    a = x;
    b = y;
    c = z;
}

std::ostream& operator << (std::ostream& os, TPolinom& polinom) {
    os << polinom.a
       << "x^2 + ("
       << polinom.b
       << ")x + ("
       << polinom.c
       << ")";

    return os;
}

number TPolinom::value (number x) {
    return (a * x * x) + (b * x) + c;
}

unsigned int TPolinom::roots (number* result) {
    number discriminant = b * b - 4 * a * c;

    if (discriminant == 0) {
        result[0] = -b / (2 * a);
        return 1;
    }

    if (discriminant > 0) {
        result[0] = (-b - sqrt(discriminant)) / (2 * a);
        result[1] = (-b + sqrt(discriminant)) / (2 * a);
        return 2;
    }

    return 0;
}
