#ifndef EVERLOOP_H
#define EVERLOOP_H

#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"

// Proxy class for everloop parameter
class led {
    public:
    led(int red, int green, int blue, int white);
    led();
    ~led();

    int r, g, b, w;
};


class everloop {
    public:
    everloop();
    ~everloop();

    int ledCount;
    void set(std::vector <led> x);
};

#endif