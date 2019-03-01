#!/usr/bin/env python

# Commands For Building #
# swig -python -py3 -c++ -outcurrentdir matrix-hal-swig/matrix.i
# python3 setup.py build_ext --inplace

"""
setup.py file for SWIG HAL wrapper
"""

from distutils.core import setup, Extension
import sysconfig

extra_compile_args = sysconfig.get_config_var('CFLAGS').split()
extra_compile_args += [
    "-std=gnu++11", 
    "-fno-threadsafe-statics", 
    "-fPIC", 
    "-O2",
    "-lmatrix_creator_hal",
    "-shared",
    "-I/usr/include/python3.5m",
    "-c"
]


matrix_module = Extension('_matrix',
    # (SHORTEN THE LENGTH OF SOURCES)
    sources=['matrix-hal-swig/matrix_wrap.cxx', 'matrix-hal-swig/matrix.cpp', 'matrix-hal-swig/drivers/everloop.cpp', 'matrix-hal-swig/drivers/gpio.cpp', 'matrix-hal-swig/drivers/sensors/imu.cpp','matrix-hal-swig/drivers/sensors/uv.cpp', 'matrix-hal-swig/drivers/sensors/pressure.cpp', 'matrix-hal-swig/drivers/sensors/humidity.cpp'],
    libraries=['matrix_creator_hal'],
    swig_opts=("-c++"),
    extra_compile_args=extra_compile_args,
    language='c++11',
    
)

setup (name = 'matrix',
       version = '0.0.1',
       author      = "MATRIX Labs",
       description = """Simple swig matrix from docs""",
       py_modules = ["matrix"],
       ext_modules = [matrix_module],
       )