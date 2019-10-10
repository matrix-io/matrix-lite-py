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

// **Exported sensors classes** //
void init_sensors(py::module &m) {
    // IMU //
    py::class_<_imu_values>(m, "_imu_values")
        .def_readonly("accel_x", &_imu_values::accel_x)
        .def_readonly("accel_y", &_imu_values::accel_y)
        .def_readonly("accel_z", &_imu_values::accel_z)
        .def_readonly("gyro_x", &_imu_values::gyro_x)
        .def_readonly("gyro_y", &_imu_values::gyro_y)
        .def_readonly("gyro_z", &_imu_values::gyro_z)
        .def_readonly("yaw", &_imu_values::yaw)
        .def_readonly("pitch", &_imu_values::pitch)
        .def_readonly("roll", &_imu_values::roll)
        .def_readonly("mag_x", &_imu_values::mag_x)
        .def_readonly("mag_y", &_imu_values::mag_y)
        .def_readonly("mag_z", &_imu_values::mag_z)
        .def("__repr__", [](const _imu_values &s) {
            return
                "accel_x: "+std::to_string(s.accel_x)+
                "\naccel_y: "+std::to_string(s.accel_y)+
                "\naccel_z: "+std::to_string(s.accel_z)+
                "\ngyro_x: "+std::to_string(s.gyro_x)+
                "\ngyro_y: "+std::to_string(s.gyro_y)+
                "\ngyro_z: "+std::to_string(s.gyro_z)+
                "\nyaw: "+std::to_string(s.yaw)+
                "\npitch: "+std::to_string(s.pitch)+
                "\nroll: "+std::to_string(s.roll)+
                "\nmag_x: "+std::to_string(s.mag_x)+
                "\nmag_y: "+std::to_string(s.mag_y)+
                "\nmag_z: "+std::to_string(s.mag_z);
            }
        );

    py::class_<imu>(m, "imu")
        .def(py::init())
        .def("read", &imu::read);

    // UV //
    py::class_<_uv_values>(m, "_uv_values")
        .def_readonly("uv", &_uv_values::uv)
        .def("__repr__", [](const _uv_values &s) {
            return
                "uv: "+std::to_string(s.uv);
            }
        );

    py::class_<uv>(m, "uv")
        .def(py::init())
        .def("read", &uv::read);

    // Humidity //
    py::class_<_humidity_values>(m, "_humidity_values")
        .def_readonly("humidity", &_humidity_values::humidity)
        .def_readonly("temperature", &_humidity_values::temperature)
        .def("__repr__", [](const _humidity_values &s) {
            return
                "humidity: "+std::to_string(s.humidity)+
                "\ntemperature: "+std::to_string(s.temperature);
            }
        );

    py::class_<humidity>(m, "humidity")
        .def(py::init())
        .def("read", &humidity::read);

    // Pressure //
    py::class_<_pressure_values>(m, "_pressure_values")
        .def_readonly("altitude", &_pressure_values::altitude)
        .def_readonly("pressure", &_pressure_values::pressure)
        .def_readonly("temperature", &_pressure_values::temperature)
        .def("__repr__", [](const _pressure_values &s) {
            return
                "altitude: "+std::to_string(s.altitude)+
                "\npressure: "+std::to_string(s.pressure)+
                "\ntemperature: "+std::to_string(s.temperature);
            }
        );
    
    py::class_<pressure>(m, "pressure")
        .def(py::init())
        .def("read", &pressure::read);
}

/////////////////////
/////   IMU    /////
imu::imu(){imu_sensor.Setup(&bus);}
_imu_values imu::read(){
    imu_sensor.Read(&imu_data);

    return _imu_values{
        accel_x: imu_data.accel_x,
        accel_y: imu_data.accel_y,
        accel_z: imu_data.accel_z,
        gyro_x:  imu_data.gyro_x,
        gyro_y:  imu_data.gyro_y,
        gyro_z:  imu_data.gyro_z,
        yaw:     imu_data.yaw,
        pitch:   imu_data.pitch,
        roll:    imu_data.roll,
        mag_x:   imu_data.mag_x ,
        mag_y:   imu_data.mag_y ,
        mag_z:   imu_data.mag_z 
    };
}

/////////////////////
/////   UV     /////
uv::uv(){uv_sensor.Setup(&bus);}

_uv_values uv::read(){
    uv_sensor.Read(&uv_data);

    return _uv_values{
        uv: uv_data.uv
    };
}

/////////////////////
///// HUMIDITY /////
humidity::humidity(){humidity_sensor.Setup(&bus);}

_humidity_values humidity::read(){
    humidity_sensor.Read(&humidity_data);

    return _humidity_values{
        humidity: humidity_data.humidity,
        temperature: humidity_data.temperature,
    };
}

/////////////////////
///// PRESSURE /////
pressure::pressure(){pressure_sensor.Setup(&bus);}

_pressure_values pressure::read(){
    pressure_sensor.Read(&pressure_data);

    return _pressure_values{
        altitude: pressure_data.altitude,
        pressure: pressure_data.pressure,
        temperature: pressure_data.temperature,
    };
}