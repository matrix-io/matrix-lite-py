#ifndef SENSORS_SENSOR_H
#define SENSORS_SENSOR_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_sensors(py::module &);

/////////////////////
/////   IMU    /////
typedef struct {
    float accel_x, accel_y, accel_z;
    float gyro_x,  gyro_y,  gyro_z;
    float yaw,     pitch,   roll;
    float mag_x,   mag_y,   mag_z;
} _imu_values;

class imu {
    public:
    imu();

    _imu_values read();
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
typedef struct {
    float humidity;
    float temperature;
} _humidity_values;

class humidity {
    public:
    humidity();

    _humidity_values read();
};

/////////////////////
///// PRESSURE /////
typedef struct {
    float altitude;
    float pressure;
    float temperature;
} _pressure_values;

class pressure {
    public:
    pressure();

    _pressure_values read();
};

#endif