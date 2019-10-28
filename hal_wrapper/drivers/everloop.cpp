#include <pybind11/pybind11.h>
#include "./everloop.h"
#include "../matrix.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
#include <stdexcept>

namespace py = pybind11;

matrix_hal::Everloop hal_everloop;

// **Exported Everloop class** //
void init_led(py::module &m) {
    py::class_<everloop>(m, "everloop")
        .def(py::init())
        .def("set", &everloop::set)
        .def_readonly("length", &everloop::led_count);
}

everloop::everloop() {
    hal_everloop.Setup(&bus);
    led_count = bus.MatrixLeds();
}

// Set everloop from list of RGBW tuples [(0,0,0,0)]
void everloop::set(py::list leds) {
    py::gil_scoped_release release;

    int new_leds = leds.size();

    // Throw error, if too many LEDs configured
    if (everloop::led_count < new_leds)
        throw std::runtime_error("Index out of bounds. This device only has " + std::to_string(everloop::led_count) + " LEDs!");

    // Create everloop image
    matrix_hal::EverloopImage everloop_image(everloop::led_count);
    for (int i = 0; i < new_leds; i++) {
        auto rgbw = leds[i].cast<py::tuple>();
        
        // Pass tuple into everloop image.
        int inputs = rgbw.size();
        everloop_image.leds[i].red   = (inputs > 0) ? rgbw[0].cast<int>() : 0;
        everloop_image.leds[i].green = (inputs > 1) ? rgbw[1].cast<int>() : 0;
        everloop_image.leds[i].blue  = (inputs > 2) ? rgbw[2].cast<int>() : 0;
        everloop_image.leds[i].white = (inputs > 3) ? rgbw[3].cast<int>() : 0;
    }

    // Render everloop image
    hal_everloop.Write(&everloop_image);
}
