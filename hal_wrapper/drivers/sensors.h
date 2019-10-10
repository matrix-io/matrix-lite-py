#ifndef SENSORS_SENSOR_H
#define SENSORS_SENSOR_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_sensors(py::module &);

/////////////////////
/////   IMU    /////
class imu {
    public:
    imu();

    py::object read();
};

/////////////////////
/////   UV     /////
typedef struct {
    float uv;
} _uv_values;

class uv {
    public:
    uv();

    _uv_values read();
};

/////////////////////
///// HUMIDITY /////
class humidity {
    public:
    humidity();

    py::object read();
};

/////////////////////
///// PRESSURE /////
class pressure {
    public:
    pressure();

    py::object read();
};

#endif