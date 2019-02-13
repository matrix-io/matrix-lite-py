#!/usr/bin/env python

"""
setup.py file for SWIG matrix
"""

from distutils.core import setup, Extension


matrix_module = Extension('_matrix',
                           sources=['hal_wrapper/matrix_wrap.cxx', 'hal_wrapper/matrix.cpp'],
                           )

setup (name = 'matrix',
       version = '0.0.0',
       author      = "MATRIX Labs",
       description = """MATRIX Lite for python""",
       ext_modules = [matrix_module],
       py_modules = ["matrix"],
       )