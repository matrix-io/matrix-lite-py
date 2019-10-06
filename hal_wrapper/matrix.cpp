#include <pybind11/pybind11.h>
#include "./matrix.h"
#include "./drivers/everloop.h"
#include "./drivers/sensors.h"
#include "./drivers/gpio.h"
#include "./drivers/info.h"
#include <map>

// Declare bus for MATRIX hardware communication
matrix_hal::MatrixIOBus bus;

// Initialize MATRIX bus
bool busReady = bus.Init();

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(_matrix_hal, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    init_led(m);
    init_sensors(m);
    init_gpio(m);
    init_info(m);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}

// Helper functions for pybind11
namespace pyHelp {
    // - Convert python String to lowercase c++ string
    std::string to_lower_case(py::str py_str){
        std::string str = py_str.cast<std::string>();

        for(uint i=0;i<str.length();i++)
            str.at(i)=std::tolower(str.at(i));

        return str;
    }

    // - Return c++ map from python dictionary
    std::map<std::string, pybind11::handle> dict_to_map(py::dict dict){
        std::map<std::string, pybind11::handle> map;
        
        for (auto item : dict)
            map[std::string(py::str(item.first))]=item.second;
        
        return map;
    }
}
