#include <pybind11/pybind11.h>
#include "./info.h"
#include "../matrix.h"

namespace py = pybind11;

info::info(){}

// **Exported Info class** //
void init_info(py::module &m) {
    py::class_<info>(m, "info")
        .def(py::init())
        .def("isDirectBus", &info::isDirectBus);
}

// Determine if MATRIX is using bus or kernel modules
bool info::isDirectBus(){
    // Kernel Modules are being used
    if(!bus.IsDirectBus()) {return false;}
    // Bus is being used
    else {return true;}
}