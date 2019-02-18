#include "sensors.h"
#include "../../matrix.h"
#include "matrix_hal/pressure_sensor.h"
#include "matrix_hal/pressure_data.h"

matrix_hal::PressureData pressure_data;
matrix_hal::PressureSensor pressure_sensor;

pressure::pressure(){
    // Start sensor
    pressure_sensor.Setup(&bus);
}
pressure::~pressure(){}

// - Returns sensor data
pressure_struct pressure::read(){
    pressure_struct data;

    // Update output values
    pressure_sensor.Read(&pressure_data);

    data.altitude = pressure_data.altitude;
    data.pressure = pressure_data.pressure;
    data.temperature = pressure_data.temperature;

    return data;
}