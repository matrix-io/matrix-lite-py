#ifndef GPIO_H
#define GPIO_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_gpio(py::module &);

class gpio {
    public:
    gpio();
    
    bool setMode(py::args);
    bool setFunction(py::args);
    bool setDigital(py::args);
    int  getDigital(int);
    bool setPWM(py::dict);
    // bool setServoAngle(int pin, float angle, float min_pulse_ms);
};

#endif