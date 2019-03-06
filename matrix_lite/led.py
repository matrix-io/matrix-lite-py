# from matrix import everloop, led
# from matrix_lite.matrix import everloop, led

from halSwig import everloop, led

everloop = everloop()

def ledTest():
    print(everloop.ledCount)
    print("LED TEST WORKEDD :D:D:D:D:D:D")