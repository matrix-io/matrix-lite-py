# MATRIX-Lite-PY
**Under Development**

# Roadmap
This roadmap is for creating a library out of the checklist below. [swigExamples.py](swigExamples.py) will contain examples of the direct [SWIG](https://github.com/matrix-io/matrix-hal-swig/tree/c66eebc4318f3f9147649a617cf0d708575bfac8) implementations.

> **As this package develops, the API will improve and change.**
- [ ] Leds
- [x] Sensors
  - [x] IMU
  - [x] Humidity
  - [x] Pressure
  - [x] UV
- [ ] GPIO
- [ ] Microphones
  - [ ] Hal Mics
  - [ ] Alsa Mics

# Development Dependencies
Ensure you have a Raspberry Pi, attached with a MATRIX device, that's flashed with [Raspbian Stretch](https://www.raspberrypi.org/blog/raspbian-stretch/).

Install SWIG 
```bash
sudo apt-get install swig
```
Install pip3
```
sudo apt-get install python3-pip
```

## 1. Install MATRIX HAL
https://matrix-io.github.io/matrix-documentation/matrix-hal/getting-started/installation-package/

## 2. Clone & Build the repository
This will compile SWIG wrapper for HAL.
```
git clone --recurse-submodules https://github.com/matrix-io/matrix-lite-py
cd matrix-lite-py && git checkout cc/pySetup
cd matrix-hal-swig && git checkout master
cd ..

mkdir -p build
swig -python -py3 -c++ -outdir build matrix-hal-swig/matrix.i
python3 setup.py sdist bdist_wheel

pip3 install dist/matrix_lite-0.0.1-cp35-cp35m-linux_armv7l.whl
```
<!-- 
longer git clone alternative:
git clone https://github.com/matrix-io/matrix-lite-py
git submodule init
git submodule update 
-->

## 3. Run the python script
```
python3 swigExamples.py
```
