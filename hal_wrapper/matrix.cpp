#include "matrix.h"
#include <stdio.h>
#include <iostream>                                                             

// Hal dependencies
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"

matrix_hal::MatrixIOBus bus;

matrix::matrix(){} // constructor
matrix::~matrix(){} // deconstructor

void matrix::speak(){
  printf("I 2 human 4 U.\n");
}

void matrix::ledTest(){
    printf("LED test\n");
    matrix_hal::MatrixIOBus bus;
    if (!bus.Init()) printf("ERROR OCCURRED!\n");;

    int ledCount = bus.MatrixLeds();
    matrix_hal::EverloopImage everloop_image(ledCount);
    matrix_hal::Everloop everloop;
    everloop.Setup(&bus);

    for (matrix_hal::LedValue &led : everloop_image.leds) {
        led.red = 1;
        led.green = 0;
        led.blue = 1;
        led.white = 0;
    }

    everloop.Write(&everloop_image);
}