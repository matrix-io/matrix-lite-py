#!/bin/bash

# Initialize matrix-hal-swig submodule
git submodule update --init --recursive

# Pretend boot files exists
touch /boot/config.txt
touch /boot/cmdline.txt

# Grab MATRIX Repositories
curl https://apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian stretch main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

# Raspberry Pi Dependencies
sudo apt-get install -y apt-transport-https systemd swig
sudo apt-get update

# MATRIX Dependencies
sudo apt-get install -y matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev

# Download available Python 3 versions
sudo apt-get install -y python3.4-dev
sudo apt-get install -y python3.5-dev

# Compile matrix-lite for desired Python 3 versions
compile_lite () {
    # create python3.x enviorment
    virtualenv -p python$1 --clear env && source env/bin/activate
    # compile matrix-lite-py
    mkdir -p build
    swig -python -py3 -c++ -outdir build matrix-hal-swig/matrix.i
    python3 setup.py sdist bdist_wheel
    # export compiled library to shared volume
    cp dist/* /volume
    # cleanup changes
    deactivate
    git reset --hard && git add . && git clean -fdX
}

compile_lite 3.4
compile_lite 3.5
compile_lite 3.7