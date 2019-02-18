#include "sensors.h"
#include "../../matrix.h"
#include "matrix_hal/uv_sensor.h"
#include "matrix_hal/uv_data.h"

matrix_hal::UVData uv_data;
matrix_hal::UVSensor uv_sensor;

uv::uv(){
    // Start sensor
    uv_sensor.Setup(&bus);
}
uv::~uv(){}

// - Returns sensor data
uv_struct uv::read(){
    uv_struct data;

    // Update output values
    uv_sensor.Read(&uv_data);

    data.uv = uv_data.uv;

    return data;
}