import colour
from halSwig import everloop, led

_everloop = everloop()
length = _everloop.ledCount

# Sets the current everloop image on MATRIX Device
def set(config = None):
    # Determine input type #
    # Set everloop LEDs for each list value
    if isinstance(config, list):
        print("You put a list, but this isn't done yet... come back later")
    # Set everloop as one value
    elif isinstance(config, str) or isinstance(config, dict) or isinstance(config, tuple):
        rgbw = _readColor(config)
        newLed = led(rgbw['r'],rgbw['g'],rgbw['b'],rgbw['w'])
        _everloop.set([led(rgbw['r'],rgbw['g'],rgbw['b'],rgbw['w'])] * length)
    # Throw error on invalid input
    else:
        raise Exception("led.set() only accepts a value or list of values from: strings, tuples & dicts")

# Returns RGBW of inputs: string, tuple, & dict
def _readColor(color):
    # Handle dict input
    if isinstance(color, dict):
        return {"r": color.get("r", 0), "g": color.get("g", 0),"b": color.get("b", 0),"w": color.get("w", 0),}
    
    # Handle string/tuple input #
    rgbw = [0, 0, 0, 0]
    offset = 1 # offset for colour.Color().rgb decimal return
    
    # Convert string input to tuple
    if isinstance(color, str):
        color = colour.Color(color).rgb
        offset = 255

    # Convert tuple to dict
    for i, value in enumerate(color):
        rgbw[i] = int(color[i]*offset)

    return { "r": rgbw[0], "g": rgbw[1], "b": rgbw[2], "w": rgbw[3] }