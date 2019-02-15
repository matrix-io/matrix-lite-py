#include "everloop.h"
#include "../matrix.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
// #include <iostream>                                                             

everloop::everloop(){} // constructor
everloop::~everloop(){} // deconstructor

// - return number of LEDs on device
int everloop::ledCount(){
    return bus.MatrixLeds();
}

// - test LED color change
matrix_hal::Everloop everloop;
void everloop::ledTest(){
    int ledCount = bus.MatrixLeds();
    matrix_hal::EverloopImage everloop_image(ledCount);
    matrix_hal::Everloop everloop;
    everloop.Setup(&bus);

    for (matrix_hal::LedValue &led : everloop_image.leds) {
        led.red = 0;
        led.green = 0;
        led.blue = 1;
        led.white = 0;
    }

    everloop.Write(&everloop_image);
}