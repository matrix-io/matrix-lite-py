#ifndef SENSORS_SENSOR_H
#define SENSORS_SENSOR_H

#include <pybind11/pybind11.h>
namespace py = pybind11;
void init_sensors(py::module &);

class imu {
    public:
    imu();

    py::object read();
};

class uv {
    public:
    uv();

    py::object read();
};

class humidity {
    public:
    humidity();

    py::object read();
};

class pressure {
    public:
    pressure();

    py::object read();
};

#endif