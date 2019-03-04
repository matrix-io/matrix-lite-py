#!/usr/bin/env python
"""
setup.py file for SWIG HAL wrapper
"""
import os
from distutils.core import setup, Extension


# Grab all cppFiles
def getCppFiles(folders):
    files = []

    for folder in folders:
        for file in os.listdir(folder):
            if file.endswith('.cpp') or file.endswith('.cxx'):
                files.append(folder + '/' + file) 
    return files

# Module dependencies
matrix_module = Extension('_matrix',
    sources = getCppFiles([
        'matrix-hal-swig', 
        'matrix-hal-swig/drivers', 
        'matrix-hal-swig/drivers/sensors']
    ),
    libraries=['matrix_creator_hal']
)

# Setup information
setup (name = 'matrix',
       version = '0.0.1',
       author      = "MATRIX Labs",
       description = """Simple swig matrix from docs""",
       py_modules = ["matrix"],
       ext_modules = [matrix_module],
       )