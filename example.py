from ctypes import cdll
lib = cdll.LoadLibrary('./build/libfoo.so')

# class Matrix(object):
#     def __init__(self):
#         self.obj = lib.Matrix_new()

#     carlos = lib.carlos

#     def bar(self):
#         lib.Matrix_bar(self.obj)


# f = Matrix()
# f.bar()
print(lib.our_function([321,456,789]))
