all:
	# build destination
	mkdir -p build;
	# create python wrapper
	swig -python -c++ -outdir build hal_wrapper/matrix.i
	# create python library
	python3 setup.py build_ext --build-lib build --build-temp build/temp
	# remove generated wrap
	rm hal_wrapper/matrix_wrap.cxx