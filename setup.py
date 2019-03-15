#!/usr/bin/env python
"""
setup.py file for SWIG HAL wrapper
"""
import os
# from distutils.core import setup, Extension
from setuptools import setup, Extension, find_packages

# Grabs all cppFiles
def getCppFiles(folders):
    files = []

    for folder in folders:
        for file in os.listdir(folder):
            if file.endswith('.cpp') or file.endswith('.cxx'):
                files.append(folder + '/' + file) 
    return files

# Module dependencies
matrix_module = Extension('_halSwig',
    sources = getCppFiles(['matrix-hal-swig', 'matrix-hal-swig/drivers', 'matrix-hal-swig/drivers/sensors']),
    libraries=['matrix_creator_hal'],
)

# Setup information
setup (name = 'matrix-lite',
       version = '0.0.1',
       author      = "MATRIX Labs",
       description = """Simple swig matrix from docs""",
       packages = find_packages(),
       ext_modules = [matrix_module],
       options = {'build':{'build_lib':'build', 'build_temp':'build'}},
       zip_safe = False,
       )