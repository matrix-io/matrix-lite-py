import colour
from halSwig import everloop, led as ledConfig

_led = everloop()
length = _led.ledCount

# Sets the current everloop image on MATRIX Device
def set(config = None):
    everloop = []

    # # Default argument turns LEDs off
    # if config == None:
    #     _led.set([])

    # # Handle list argument
    # elif isinstance(config, list):
    #     print("you inserted a list")

    # # Handle string argument
    # elif isinstance(config, str):
    #     print("you inserted a string")
    # else:
    #     raise Exception("you inserted an invalid input")

# Returns RGBW of inputs: string, tuple, & dict
def _readColor(color):
    newColor = {"r":0, "g":0, "b":0, "w":0,}

    # Handle tuple inputs with 0-4 values
    if isinstance(color, tuple):
        newColor['r'] = color[0] or 0
        newColor['g'] = color[1] or 0
        newColor['b'] = color[2] or 0
        newColor['w'] = color[3] or 0

        # Previous loop (fix later)
        # for i, value in enumerate(color):
        #     # print(newColor.values()[i])
        #     newColor[list(newColor.keys())[i]] = color[i]

    # Handle string inputs with pypi colour
    elif isinstance(color, str):
        color = colour.Color(color).rgb
        newColor['r'] = int(color[0]*255)
        newColor['g'] = int(color[1]*255)
        newColor['b'] = int(color[2]*255)

    # Handle dict inputs
    # ...

    print(newColor)