#include "matrix.h"

// Hal dependencies
// #include "matrix_hal/everloop.h"
// #include "matrix_hal/everloop_image.h"
// #include "matrix_hal/matrixio_bus.h"

int fact(int n) {
    return n + 100;
}

// void ledTest(){
//     matrix_hal::MatrixIOBus bus;
//     // if (!bus.Init()) return false;

//     int ledCount = bus.MatrixLeds();
//     matrix_hal::EverloopImage everloop_image(ledCount);
//     matrix_hal::Everloop everloop;
//     everloop.Setup(&bus);

//     for (matrix_hal::LedValue &led : everloop_image.leds) {
//         led.red = 0;
//         led.green = 100;
//         led.blue = 0;
//         led.white = 0;
//     }

//     everloop.Write(&everloop_image);
// }

