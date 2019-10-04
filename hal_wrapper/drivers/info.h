#ifndef INFO_H
#define INFO_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_info(py::module &);

class info {
    public:
    info();

    bool isDirectBus();
};

#endif