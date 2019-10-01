from matrix_lite import sensors
import hal
from time import sleep

print(dir(hal))

while True:
    print(sensors.imu.read())
    # print(sensors.uv.read())
    # print(sensors.humidity.read())
    # print(sensors.pressure.read())