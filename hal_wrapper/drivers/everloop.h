#ifndef EVERLOOP_H
#define EVERLOOP_H

#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"

// Proxy class for everloop parameter
class led {
    public:
    led();
    led(int red, int green, int blue, int white);
    
    ~led();

    int r, g, b, w;
};


class everloop {
    public:
    everloop();
    ~everloop();

    int ledCount;
    void ledTest(std::vector <led> x);
};

#endif