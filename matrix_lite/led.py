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
    # Handle dict input
    if isinstance(color, dict):
        return color

    rgbw = [0, 0, 0, 0]
    
    # Convert string input to tuple
    offset = 1
    if isinstance(color, str):
        color = colour.Color(color).rgb
        offset = 255 # offset for .rgb decimal return

    # Handle tuple input
    for i, value in enumerate(color):
        rgbw[i] = int(color[i]*offset)

    return { "r": rgbw[0], "g": rgbw[1], "b": rgbw[2], "w": rgbw[3] }