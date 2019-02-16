#include "matrix.h"
#include <stdio.h>

// Declare bus for MATRIX hardware communication
matrix_hal::MatrixIOBus bus;

// Initialize MATRIX bus
bool busReady = bus.Init();