all:
	mkdir -p build;
	# create python wrapper
	swig -python -c++ -outdir build hal_wrapper/matrix.i
	# create python library
	python3 setup.py build_ext --build-lib build --build-temp build/temp


# Previous use
# all:
# 	# mkdir -p build;
# 	swig -python -c++ hal_wrapper/matrix.i

# 	# build_ext command
# 	python3 setup.py build_ext --build-lib hal_wrapper --build-temp temp