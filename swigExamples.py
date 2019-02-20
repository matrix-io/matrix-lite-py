import build.matrix as hal
from time import sleep


# Print exported objects/functions
print(dir(hal))

## LED Example ##
everloop = hal.everloop()

leds = []
for i in range(everloop.ledCount):
    led = hal.led(0,0,1,0)#led.r led.g led.b led.w
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
gpio = hal.gpio()
print(dir(gpio))
print(gpio.setMode(0,0))
print(gpio.setFunction(0,0))

while True:
    print(gpio.getValue(0))
    sleep(0.05)