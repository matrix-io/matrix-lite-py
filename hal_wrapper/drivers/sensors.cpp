#include <pybind11/pybind11.h>
#include <iostream>
#include "./sensors.h"
#include "../matrix.h"
#include "matrix_hal/imu_sensor.h"
#include "matrix_hal/imu_data.h"
#include "matrix_hal/uv_sensor.h"
#include "matrix_hal/uv_data.h"
#include "matrix_hal/pressure_sensor.h"
#include "matrix_hal/pressure_data.h"
#include "matrix_hal/humidity_sensor.h"
#include "matrix_hal/humidity_data.h"

namespace py = pybind11;

matrix_hal::IMUData imu_data;
matrix_hal::IMUSensor imu_sensor;
matrix_hal::UVData uv_data;
matrix_hal::UVSensor uv_sensor;
matrix_hal::PressureData pressure_data;
matrix_hal::PressureSensor pressure_sensor;
matrix_hal::HumidityData humidity_data;
matrix_hal::HumiditySensor humidity_sensor;

// **Exported sensors class** //
void init_sensors(py::module &m) {
    // IMU //
    py::class_<imu>(m, "imu")
        .def(py::init())
        .def("read", &imu::read);

    // UV //
    py::class_<_uv_values>(m, "_uv_values")
        .def_readonly("uv", &_uv_values::uv);

    py::class_<uv>(m, "uv")
        .def(py::init())
        .def("read", &uv::read);

    // Pressure //
    py::class_<pressure>(m, "pressure")
        .def(py::init())
        .def("read", &pressure::read);

    // Humidity //
    py::class_<humidity>(m, "humidity")
        .def(py::init())
        .def("read", &humidity::read);
}

/////////////////////
/////   IMU    /////
imu::imu(){imu_sensor.Setup(&bus);}
py::object imu::read(){
    imu_sensor.Read(&imu_data);

    auto data = py::dict();
    data["accel_x"] = imu_data.accel_x;
    data["accel_y"] = imu_data.accel_y;
    data["accel_z"] = imu_data.accel_z;
    data["gyro_x"]  = imu_data.gyro_x;
    data["gyro_y"]  = imu_data.gyro_y;
    data["gyro_z"]  = imu_data.gyro_z;
    data["yaw"]     = imu_data.yaw;
    data["pitch"]   = imu_data.pitch;
    data["roll"]    = imu_data.roll;
    data["mag_x"]   = imu_data.mag_x;
    data["mag_y"]   = imu_data.mag_y;
    data["mag_z"]   = imu_data.mag_z;

    return data;
}

/////////////////////
/////   UV     /////
uv::uv(){uv_sensor.Setup(&bus);}

_uv_values uv::read(){
    uv_sensor.Read(&uv_data);

    std::cout << imu_data.accel_x << std::endl;

    return _uv_values{
        uv: imu_data.accel_x
    };
}

/////////////////////
///// PRESSURE /////
pressure::pressure(){pressure_sensor.Setup(&bus);}
py::object pressure::read(){
    pressure_sensor.Read(&pressure_data);

    auto data = py::dict();
    data["altitude"] = pressure_data.altitude;
    data["pressure"] = pressure_data.pressure;
    data["temperature"] = pressure_data.temperature;

    return data;
}

/////////////////////
///// HUMIDITY /////
humidity::humidity(){humidity_sensor.Setup(&bus);}
py::object humidity::read(){
    humidity_sensor.Read(&humidity_data);

    auto data = py::dict();
    data["humidity"] = humidity_data.humidity;
    data["temperature"] = humidity_data.temperature;

    return data;
}
