#include "sensors.h"
#include "../../matrix.h"
#include "matrix_hal/imu_sensor.h"
#include "matrix_hal/imu_data.h"

matrix_hal::IMUData imu_data;
matrix_hal::IMUSensor imu_sensor;

imu::imu(){
    // Start sensor
    imu_sensor.Setup(&bus);
}
imu::~imu(){}

// - Returns sensor data
imu_struct imu::read(){
    imu_struct data;

    // Update output values
    imu_sensor.Read(&imu_data);

    // Accelerometer Output
    data.accel_x = imu_data.accel_x;
    data.accel_y = imu_data.accel_y;
    data.accel_z = imu_data.accel_z;
    // Gyroscope Output
    data.gyro_x = imu_data.gyro_x;
    data.gyro_y = imu_data.gyro_y;
    data.gyro_z = imu_data.gyro_z;
    // Yaw, Pitch, Roll Output
    data.yaw = imu_data.yaw;
    data.pitch = imu_data.pitch;
    data.roll = imu_data.roll;
    // Magnetometer Output
    data.mag_x = imu_data.mag_x;
    data.mag_y = imu_data.mag_y;
    data.mag_z = imu_data.mag_z;

    return data;
}