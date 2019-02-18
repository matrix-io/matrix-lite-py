#include "everloop.h"
#include "../matrix.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
#include <stdexcept>

matrix_hal::Everloop hal_everloop;

// LED //
led::led(int red, int green, int blue, int white){
    r = red;
    g = green;
    b = blue;
    w = white;
}
led::led(){
    r = 0;
    g = 0;
    b = 0;
    w = 0;
}
led::~led(){}

// EVERLOOP //
everloop::everloop(){
    // setup hal everloop
    hal_everloop.Setup(&bus);

    // get number device LEDs
    ledCount = bus.MatrixLeds();
}
everloop::~everloop(){} 

// - test LED color change
void everloop::set(std::vector <led> ledState){
    int ledsSet = ledState.size();

    // Throw, if too many LEDs configured
    if (everloop::ledCount < ledsSet){
        std::string text = "Index out of bounds. Device LED count: ";
        text += std::to_string(everloop::ledCount);
        throw std::runtime_error(text);
    }

    // Create everloop image
    matrix_hal::EverloopImage everloop_image(everloop::ledCount);
    for (int i = 0; i < ledsSet; i++){
        everloop_image.leds[i].red = ledState[i].r;
        everloop_image.leds[i].green = ledState[i].g;
        everloop_image.leds[i].blue = ledState[i].b;
        everloop_image.leds[i].white = ledState[i].w;
    }

    // Render everloop image
    hal_everloop.Write(&everloop_image);
}