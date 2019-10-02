#ifndef EVERLOOP_H
#define EVERLOOP_H

#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_led(py::module &);

class everloop {
    public:
    everloop();

    int led_count;
    void set(py::list);
};

#endif