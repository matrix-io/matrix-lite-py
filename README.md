# MATRIX-Lite-Py
**Under Development**

# Roadmap
This roadmap is for creating a library out of the checklist below. [swigExamples.py](swigExamples.py) will contain examples of the direct [SWIG](https://github.com/matrix-io/matrix-hal-swig/tree/c66eebc4318f3f9147649a617cf0d708575bfac8) implementations.

> **As this package develops, the API will improve and may change.**
- [ ] Leds
- [ ] Sensors
  - [ ] IMU
  - [ ] Humidity
  - [ ] Pressure
  - [ ] UV
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
cd matrix-lite-py


# swig -python -py3 -c++ -outdir halWrapper matrix-hal-swig/matrix.i
# python3 setup.py build_ext --build-lib matrix-hal-wrap

# mkdir -p halWrapper
# swig -python -py3 -c++ -outcurrentdir matrix-hal-swig/matrix.i
# mv matrix_wrap.cxx matrix-hal-swig
# python3 setup.py build_ext --inplace

## Winning Compiling Steps! ##
mkdir -p swigBuild
swig -python -py3 -c++ -outdir swigBuild matrix-hal-swig/matrix.i
python3 setup.py build_ext -b swigBuild -t swigBuild

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

