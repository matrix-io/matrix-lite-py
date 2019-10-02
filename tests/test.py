from matrix_lite import led, sensors, gpio
import matrix_hal as hal
from time import sleep

print (gpio.__dir__())

# GPIO
print(gpio.setMode(0, "INPuT"))
print(gpio.setFunction(0, "DiGITal"))

# while True:
#     print(gpio.getDigital(0))
#     sleep(1)

# Set GPIO pin 2 (PWM)
gpio.setFunction(2, 'PWM')
gpio.setMode(2, 'output')
gpio.setPWM({
    "pin": 2,
    "percentage": 25,
    "frequency": 50, # min 36
})

# LEDs
# led.set([(20,0,0,0), (1,0,0,0)])

# everloop = [{}] * led.length
# everloop[0] = (0,0,1,0)

# while True:
#     everloop.append(everloop.pop(0))
#     led.set(everloop)
#     sleep(0.0001)

# # SENSORS
# print(sensors.imu.read())
# print(sensors.uv.read())
# print(sensors.humidity.read())
# print(sensors.pressure.read())