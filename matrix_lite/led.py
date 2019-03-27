import colour
from halSwig import everloop, led

_everloop = everloop()
length = _everloop.ledCount

# Colors corrected for LED
colour.COLOR_NAME_TO_RGB["orange"] = (255, 35, 0)
colour.COLOR_NAME_TO_RGB["hotpink"] = (255, 5, 14)
colour.COLOR_NAME_TO_RGB["lightblue"] = (0, 50, 255)
colour.COLOR_NAME_TO_RGB["lightgreen"] = (20, 255, 30)

# Sets the current everloop image on MATRIX Device
def set(config = []):
    # Map LED color to array index
    if isinstance(config, list):
        # Create LED array with each LED off
        everloopImage = [led(0,0,0,0)] * length
        
        # Assign given colors into the LED array
        for i in range(0, len(config)):
            rgbw = _readColor(config[i])
            everloopImage[i] = led(rgbw['r'],rgbw['g'],rgbw['b'],rgbw['w'])
        
        _everloop.set(everloopImage)

    # Set each LED to one color
    elif isinstance(config, str) or isinstance(config, dict) or isinstance(config, tuple):
        rgbw = _readColor(config)
        _everloop.set([led(rgbw['r'],rgbw['g'],rgbw['b'],rgbw['w'])] * length)
    
    # Throws error on invalid input
    else:
        raise Exception("led.set() only accepts a value or list of values from: strings, tuples & dicts")

# Returns RGBW of inputs: string, tuple, & dict
def _readColor(color = (0,0,0,0)):
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