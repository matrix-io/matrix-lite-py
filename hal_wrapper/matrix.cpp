#include <pybind11/pybind11.h>
#include "./matrix.h"
#include "./drivers/sensors.h"

// Declare bus for MATRIX hardware communication
matrix_hal::MatrixIOBus bus;

// Initialize MATRIX bus
bool busReady = bus.Init();

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(hal, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    m.attr("num") = 42;
    init_sensors(m);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}