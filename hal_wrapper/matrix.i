%module matrix

%{
#include "matrix.h"
#include "./drivers/everloop.h"
%}

// Exposes everything in header files
%include "matrix.h"
%include "./drivers/everloop.h"