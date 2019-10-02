from matrix_lite import sensors
import matrix_hal as hal
from time import sleep

print(dir(hal))

led = hal.everloop()
print(led.length)

led.set([{'r':50,'b':50, 'g':0},{'r':10},{'b':10}])

everloop = [{}] * led.length
everloop[0] = {'b':100}

while True:
    everloop.append(everloop.pop(0))
    led.set(everloop)
    # sleep(0.000)

# print(sensors.imu.read())
# print(sensors.uv.read())
# print(sensors.humidity.read())
# print(sensors.pressure.read())