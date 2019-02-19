all:
	# build destination
	mkdir -p build;

	# generate HAL wrapper
	swig -python -c++ -outdir build matrix-hal-swig/matrix.i;	

	# compile Python library
	gcc -O2 -fPIC -c -std=gnu++11 -fno-threadsafe-statics matrix-hal-swig/matrix.cpp matrix-hal-swig/drivers/*.cpp matrix-hal-swig/drivers/sensors/*.cpp
	mv *.o build
	
	# handy to use: python-config --cflags
	gcc -O2 -fPIC -c -o build/matrix_wrap.o -std=gnu++11 -fno-threadsafe-statics matrix-hal-swig/matrix_wrap.cxx -I/usr/include/python3.5m
	gcc -lmatrix_creator_hal -shared -std=gnu++11 -fno-threadsafe-statics build/*.o -o build/_matrix.so

	# remove generated wrap
	rm matrix-hal-swig/matrix_wrap.cxx;

