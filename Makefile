all:
	# build destination
	mkdir -p build;

	# create HAL wrapper
	swig -python -c++ -outdir build hal_wrapper/matrix.i;	
	
	# compile Python library
	# TODO: COMPILE MULTIPLE FILES
	gcc -O2 -fPIC -c -o build/matrix.o -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix.cpp
	gcc -O2 -fPIC -c -o build/matrix_wrap.o -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix_wrap.cxx -I/usr/include/python3.5m
	gcc -lmatrix_creator_hal -shared -std=gnu++11 -fno-threadsafe-statics build/matrix.o build/matrix_wrap.o -o build/_matrix.so

	# remove generated wrap
	rm hal_wrapper/matrix_wrap.cxx;


# handy to use: python-config --cflags