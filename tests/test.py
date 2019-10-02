from matrix_lite import sensors
# import matrix_hal as hal
from matrix_lite import led
from time import sleep


led.set([(20,0,0,0), (1,0,0,0)])

everloop = [{}] * led.length
everloop[0] = {'r': 100}

while True:
    everloop.append(everloop.pop(0))
    led.set(everloop)
    sleep(0.0)

# print(sensors.imu.read())
# print(sensors.uv.read())
# print(sensors.humidity.read())
# print(sensors.pressure.read())