#ifndef EVERLOOP_H
#define EVERLOOP_H

#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"

class led {
    public:
    led();
    ~led();

    int r, g, b, w;

    void colorPrint();
};

class everloop {
    public:
    everloop();
    ~everloop();

    int ledCount;
    void ledTest(led color);
};

#endif