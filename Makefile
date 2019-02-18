all:
	# build destination
	mkdir -p build;

	# create HAL wrapper
	swig -python -c++ -outdir build hal_wrapper/matrix.i;	

	# compile Python library
	gcc -O2 -fPIC -c -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix.cpp hal_wrapper/drivers/*.cpp hal_wrapper/drivers/sensors/*.cpp
	mv *.o build
	
	# handy to use: python-config --cflags
	gcc -O2 -fPIC -c -o build/matrix_wrap.o -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix_wrap.cxx -I/usr/include/python3.5m
	gcc -lmatrix_creator_hal -shared -std=gnu++11 -fno-threadsafe-statics build/*.o -o build/_matrix.so

	# remove generated wrap
	rm hal_wrapper/matrix_wrap.cxx;

