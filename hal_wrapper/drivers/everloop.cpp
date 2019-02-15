#include "everloop.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"

int counter(){
    return 12345;
}

// create Everloop object
// matrix_hal::Everloop everloop;

// void matrix::ledTest2(){
//     printf("LED test\n");
//     matrix_hal::MatrixIOBus bus;
//     if (!bus.Init()) printf("ERROR OCCURRED!\n");;

//     int ledCount = bus.MatrixLeds();
//     matrix_hal::EverloopImage everloop_image(ledCount);
//     matrix_hal::Everloop everloop;
//     everloop.Setup(&bus);

//     for (matrix_hal::LedValue &led : everloop_image.leds) {
//         led.red = 1;
//         led.green = 0;
//         led.blue = 0;
//         led.white = 0;
//     }

//     everloop.Write(&everloop_image);
// }