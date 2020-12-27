#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <iostream>
#include "number.h"
#include <math.h>

class TPolinom {
    number a, b, c;
public:
    TPolinom (number, number, number);
    friend std::ostream& operator << (std::ostream&, TPolinom&);
    number value (number);
    unsigned int roots (number* result);
};

#endif // TPOLINOM_H
