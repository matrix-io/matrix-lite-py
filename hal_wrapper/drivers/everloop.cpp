#include <pybind11/pybind11.h>
#include "./everloop.h"
#include "../matrix.h"
#include "matrix_hal/everloop.h"
#include "matrix_hal/everloop_image.h"
#include <stdexcept>
#include <iostream>
#include <map>

namespace py = pybind11;

matrix_hal::Everloop hal_everloop;

// Exported Everloop class
void init_led(py::module &m) {
    py::class_<everloop>(m, "everloop")
        .def(py::init())
        .def("set", &everloop::set)
        .def_readonly("length", &everloop::ledCount);
}

everloop::everloop() {
    hal_everloop.Setup(&bus);
    ledCount = bus.MatrixLeds();
}

void everloop::set(py::list leds) {
    int new_leds = leds.size();

    // Throw error, if too many LEDs configured
    if (everloop::ledCount < new_leds)
        throw std::runtime_error("Index out of bounds. This device only has " + std::to_string(everloop::ledCount) + " LEDs!");

    // Create everloop image
    matrix_hal::EverloopImage everloop_image(everloop::ledCount);
    for (int i = 0; i < new_leds; i++) {
        std::map<std::string,int> rgbw;

        py::dict dict = leds[i].cast<py::dict>();
        for (auto item : dict){
            rgbw[std::string(py::str(item.first))]=(item.second.cast<int>());
            std::cout << "key=" << std::string(py::str(item.first)) << ", " << "value=" << std::string(py::str(item.second)) << std::endl;
        }

        everloop_image.leds[i].red   = rgbw["r"];
        everloop_image.leds[i].green = rgbw["g"];
        everloop_image.leds[i].blue  = rgbw["b"];
        everloop_image.leds[i].white = rgbw["w"];
    }

    // Render everloop image
    hal_everloop.Write(&everloop_image);
}