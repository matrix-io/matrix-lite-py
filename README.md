# MATRIX-Lite-PY
**Under Development**

MATRIX Lite PY is a library that allows users of varying skill levels to easily program their MATRIX Device.

# Roadmap
This roadmap is for achieving a basic implementation of the checklist below. As this package develops, the API will improve and may change

- [x] Leds
- [x] Sensors
  - [x] IMU
  - [x] Humidity
  - [x] Pressure
  - [x] UV
- [x] GPIO
- [ ] Microphones
  - [ ] Hal Mics
  - [ ] Alsa Mics

# Installation

Ensure you have a Raspberry Pi, attached with a MATRIX device, that's flashed with [Raspbian Stretch](https://www.raspberrypi.org/blog/raspbian-stretch/).

## 1. Install MATRIX HAL
https://matrix-io.github.io/matrix-documentation/matrix-hal/getting-started/installation-package/

## 2. Install Python 3
```
sudo apt-get install python3-pip
```

## 3. Install matrix-lite-py
```
pip3 install matrix-lite
```


# Usage (may change in the future)
The matrix-lite package contains a `matrix_lite` & `halSwig` Python module. `halSwig` is the direct SWIG implementation. `matrix_lite` contains abstractions for `halSwig` and is what we will be using.

## Everloop
```python
from matrix_lite import led
import time

# Get LED count
print('This device has ' + str(led.length) + ' Leds')

# A single string, object, or tuple will set all LEDs
# Below are different ways of expressing a color (number values are from 0-255)
led.set('blue')
led.set('#0000ff')
# Objects and tuples can utilize the white LED
led.set({'r':0, 'g':0, 'b':255, 'w':0 })
led.set((0,0,255,0))

# LEDs off
led.set('black')
led.set([])
led.set()
led.set({})

# Arrays set individual LEDs
led.set(['red', 'gold', 'purple', {}, 'black', '#6F41C1', 'blue', {'g':255}])

# Arrays can simulate motion
everloop = ['black'] * led.length
everloop[0] = {'b':100}

while True:
    everloop.append(everloop.pop(0))
    led.set(everloop)
    time.sleep(0.050)
```

## Sensors
```python
from matrix_lite import sensors
import time

#  Sensors will update with each .read() call
while True:
    # Each .read() returns a dictionary
    print(sensors.imu.read())
    print(sensors.uv.read())
    print(sensors.humidity.read())
    print(sensors.pressure.read())

    time.sleep(0.50)
```

## GPIO
```python
from matrix_lite import gpio
# Read GPIO pin 0 (digital)
gpio.setFunction(0, 'DIGITAL')
gpio.setMode(0, 'input')
print('Pin 0 is: ' + str(gpio.getDigital(0)))

# Set GPIO pin 1 (digital)
gpio.setFunction(1, 'DIGITAL')
gpio.setMode(1, 'output')
gpio.setDigital(1, 'ON')

# Set GPIO pin 2 (PWM)
gpio.setFunction(2, 'PWM')
gpio.setMode(2, 'output')
gpio.setPWM({
    "pin": 2,
    "percentage": 25,
    "frequency": 50, # min 36
})

# Set Servo Angle pin 3
gpio.setFunction(3, 'PWM')
gpio.setMode(3, 'output')
gpio.setServoAngle({
    "pin": 3,
    "angle": 90,
    # pin, angle, min_pulse_ms (minimum pulse width for a PWM wave in milliseconds)
    "min_pulse_ms": 0.8,
})
```

# Building Locally For Development
> Follow the steps in [#Installation](#installation) for the initial dependencies you'll need.

If you want to contribute to matrix-lite-py, below are the steps to build locally. Each step should take place on your Raspberry Pi.

Install SWIG 
```bash
sudo apt-get install swig
```

## Clone & Build the repository
Download the repository
```
git clone --recurse-submodules https://github.com/matrix-io/matrix-lite-py
cd matrix-hal-swig && git checkout master
cd ..
```
>Use the commands below to compile any new changes you make.

Build a Python package and generates a .whl file
```
mkdir -p build
swig -python -py3 -c++ -outdir build matrix-hal-swig/matrix.i
python3 setup.py sdist bdist_wheel
```
Install the new `.whl` file
```
pip3 install dist/*linux_armv7l.whl
```

Your Raspberry Pi should now have a `matrix_lite` & `halSwig` module, with your changes, installed.