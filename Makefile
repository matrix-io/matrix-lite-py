all:
	# build destination
	mkdir -p build;
	# create python wrapper
	swig -python -c++ -outdir build hal_wrapper/matrix.i;
	# create python library
	# python3 setup.py build_ext --build-lib build --build-temp build/temp

	# libmatrix_creator_hal.so
	gcc -O2 -fPIC -c -o build/matrix.o -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix.cpp
	gcc -O2 -fPIC -c -o build/matrix_wrap.o -std=gnu++11 -fno-threadsafe-statics hal_wrapper/matrix_wrap.cxx -I/usr/include/python3.5m
	gcc -shared -std=gnu++11 -fno-threadsafe-statics build/matrix.o build/matrix_wrap.o -o build/_matrix.so

  # handy to use: python-config --cflags
	# g++ -fPIC -Wall -Wextra -shared matrix_wrap.cxx -o -L. -I/usr/include/python3.5m
	# g++ -fPIC -Wall -Wextra -shared mylib_wrap.cxx -o _mylib.so -L. -lmylib -I/usr/include/python2.7/ -lpython2.7 

	# remove generated wrap
	rm hal_wrapper/matrix_wrap.cxx;




	# gcc -O2 -fPIC -c -std=gnu++11 -fno-threadsafe-statics matrix.cpp
  # gcc -O2 -fPIC -c -std=gnu++11 -fno-threadsafe-statics matrix_wrap.cxx -I/usr/include/python3.5m
  # gcc -shared -std=gnu++11 -fno-threadsafe-statics matrix.o matrix_wrap.o -o _matrix.so