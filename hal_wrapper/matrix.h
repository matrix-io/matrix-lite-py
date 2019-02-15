#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_hal/matrixio_bus.h"

// Global object for MATRIX hardware communication
extern matrix_hal::MatrixIOBus bus;

class matrix {
    public:
    matrix();
    ~matrix();

    void ledTest();
    void speak();
};

#endif