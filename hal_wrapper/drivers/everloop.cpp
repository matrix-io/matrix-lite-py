#include "everloop.h"
#include "../matrix.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
#include <iostream>                                                             

// LED //
led::led(){}
led::~led(){}

void led::colorPrint(){
    std::cout << "Red: " << r << std::endl;
    std::cout << "Green: " << g << std::endl;
    std::cout << "Blue: " << b << std::endl;
    std::cout << "White: " << w << std::endl;
}

// EVERLOOP //
matrix_hal::Everloop hal_everloop;

// constructor
everloop::everloop(){
    // setup hal everloop
    hal_everloop.Setup(&bus);

    // get number device LEDs
    ledCount = bus.MatrixLeds();
}

// deconstructor
everloop::~everloop(){} 

// - test LED color change
void everloop::ledTest(led color){
    matrix_hal::EverloopImage everloop_image(everloop::ledCount);

    for (matrix_hal::LedValue &led : everloop_image.leds) {
        led.red = color.r;
        led.green = color.g;
        led.blue = color.b;
        led.white = color.w;
    }

    hal_everloop.Write(&everloop_image);
}
