#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_hal/matrixio_bus.h"
#include <pybind11/pybind11.h>
#include <map>

namespace py = pybind11;

// Global object for MATRIX hardware communication
extern matrix_hal::MatrixIOBus bus;

namespace pyHelp {
	std::string to_lower_case(py::str);
    std::map<std::string, pybind11::handle> dict_to_map(py::dict);
}
#endif