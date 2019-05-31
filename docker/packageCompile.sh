#!/bin/bash
## Script for docker to compile library package(s) ##

# Pretend boot files exists
touch /boot/config.txt
touch /boot/cmdline.txt

# Grab MATRIX Repositories
curl https://apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian stretch main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

# Raspberry Pi Dependencies
sudo apt-get install -y apt-transport-https systemd swig
sudo apt-get update
sudo apt-get -y upgrade

# MATRIX Dependencies
sudo apt-get install -y matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev

# Download MATRIX Lite Python
git clone --recurse-submodules https://github.com/matrix-io/matrix-lite-py
cd matrix-lite-py
mkdir -p build

# Compile MATRIX Lite Python
python3 -m pip install wheel
swig -python -py3 -c++ -outdir build matrix-hal-swig/matrix.i
python3 setup.py sdist bdist_wheel

# Move files into shared volume
cp dist/* /volume