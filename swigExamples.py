# swigExamples.py contains example code of the direct SWIG implementation of MATRIX HAL. 
# matrix-hal-swig repository: https://github.com/matrix-io/matrix-hal-swig
# Note, the matrix_lite module is what most users are expected to use.

import halSwig as hal
from time import sleep

# Print exported objects/functions
print(dir(hal))

## LED Example ##
everloop = hal.everloop()

leds = []
for i in range(everloop.ledCount):
    led = hal.led(1,0,1,0)#led.r led.g led.b led.w
    leds.append(led)

everloop.set(leds)

## IMU Example ##
# imu = hal.imu()
# while True:
#     data = imu.read()
#     print ("Accelerometer: (xyz)",data.accel_x, data.accel_y, data.accel_z)
#     print ("Gyroscope: (xyz)",data.gyro_x, data.gyro_y, data.gyro_z)
#     print ("Magnetometer:(xyz)", data.mag_x, data.mag_y, data.mag_z)
#     print ("Yaw Pitch Roll:", data.yaw, data.pitch, data.roll)
#     sleep(0.05)

## UV Example ##
# uv = hal.uv()
# while True:
#     data = uv.read()
#     print ("UV: ", data.uv)
#     sleep(0.05)

## Humidity Example ##
# humidity = hal.humidity()
# while True:
#     data = humidity.read()
#     print("Humidity: ", data.humidity)
#     print("Temperature: ", data.temperature)
#     sleep(0.05)

## Pressure Example ##
# pressure = hal.pressure()
# while True:
#     data = pressure.read()
#     print("Altitude: ", data.altitude)
#     print("Pressure: ", data.pressure)
#     print("Temperature: ", data.temperature)
#     sleep(0.05)

## GPIO ##
# gpio = hal.gpio()

# # turn pin 0 on
# gpio.setMode(0,1)
# gpio.setFunction(0,0)
# gpio.setDigital(0,1)

# # change pin 1 servo angle
# gpio.setMode(1,1)
# gpio.setFunction(1,1)
# gpio.setServoAngle(1, 0, 0.6)

# # edit pin 2 PWM
# gpio.setMode(2,1)
# gpio.setFunction(2,1)
# gpio.setPWM(2, 25, 50)

# # read pin 3
# gpio.setMode(3,0)
# gpio.setFunction(3,0)
# while True:
#     print(gpio.getValue(3))
#     sleep(0.05)
