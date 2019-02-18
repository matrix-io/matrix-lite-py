%module matrix

%{
#include "matrix.h"
#include "./drivers/everloop.h"
#include "./drivers/sensors/sensors.h"
%}

// Array templates (template names are irrelevant)
%include "std_vector.i"
%template(everloopImage) std::vector<led>;// array of leds
// %template(integerList) std::vector<int>; // array of ints

// Exposes header files
%include "matrix.h"
%include "./drivers/everloop.h"
%include "./drivers/sensors/sensors.h"