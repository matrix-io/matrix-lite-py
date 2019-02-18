#include "sensors.h"
#include "../../matrix.h"
#include "matrix_hal/humidity_sensor.h"
#include "matrix_hal/humidity_data.h"

matrix_hal::HumidityData humidity_data;
matrix_hal::HumiditySensor humidity_sensor;

humidity::humidity(){
    // Start sensor
    humidity_sensor.Setup(&bus);
}
humidity::~humidity(){}

// - Returns sensor data
humidity_struct humidity::read(){
    humidity_struct data;

    // Update output values
    humidity_sensor.Read(&humidity_data);

    data.humidity = humidity_data.humidity;
    data.temperature = humidity_data.temperature;

    return data;
}