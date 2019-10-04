#!/bin/bash

# Pretend boot files exists
touch /boot/config.txt
touch /boot/cmdline.txt

# Grab MATRIX Repositories
curl https://apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian stretch main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

# Raspberry Pi Dependencies
sudo apt-get install -y apt-transport-https systemd
sudo apt-get update

# MATRIX Dependencies
sudo apt-get install -y matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev

# Download available Python 3 versions
# TODO: Create Dockerimage with Python 3.5, 3.6, & 3.7 preinstalled
# Python 3.4 is depricated in pip
sudo apt-get install -y python3.5-dev
# sudo apt-get install -y python3.6-dev (package not available)
# Python 3.7 is preinstalled from docker image

# Compile matrix-lite for desired Python 3 versions
compile_lite () {
    # create python3.x enviorment
    virtualenv -p python$1 --clear env && source env/bin/activate

    pip install pybind11 setuptools wheel

    # compile matrix-lite-py
    python setup.py sdist bdist_wheel
    
    # export compiled library to shared volume
    cp dist/* /volume
    
    # cleanup enviorment & changes
    deactivate
    git reset --hard && git add . && git clean -fdX
}

compile_lite 3.5
compile_lite 3.7