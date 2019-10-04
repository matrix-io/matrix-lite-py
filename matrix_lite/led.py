import colour # TODO remove eventually
from _matrix_hal import everloop

_everloop = everloop()
length = _everloop.length

# Colors corrected for LED
colour.COLOR_NAME_TO_RGB["orange"] = (255, 35, 0)
colour.COLOR_NAME_TO_RGB["hotpink"] = (255, 5, 14)
colour.COLOR_NAME_TO_RGB["lightblue"] = (0, 50, 255)
colour.COLOR_NAME_TO_RGB["lightgreen"] = (20, 255, 30)

# Sets the current everloop image on MATRIX Device
def set(config = []):
    # Individually set LEDs
    if isinstance(config, list):
        everloopImage = [(0,0,0,0)] * length
        
        # set each led color
        for i in range(0, len(config)):
            everloopImage[i] = _readColor(config[i])
            
        _everloop.set(everloopImage)

    # Set everloop to 1 color
    elif isinstance(config, str) or isinstance(config, dict) or isinstance(config, tuple):
        rgbw = _readColor(config)
        _everloop.set([_readColor(config)] * length)
    
    # Invalid input given
    else:
        raise Exception("led.set() accepts a value or list of values from: strings, tuples & dicts")

# Return RGBW tuple from a string, tuple, or dict
def _readColor(color = (0,0,0,0)):
    # Convert dict input to tuple
    if isinstance(color, dict):
        return (color.get("r", 0), color.get("g", 0), color.get("b", 0), color.get("w", 0))
    
    # Convert string input to tuple
    if isinstance(color, str):
        color = colour.Color(color).rgb + (0,)
        return (int(255*color[0]),int(255*color[1]),int(255*color[2]),int(255*color[3]))

    # Tuples are already handeled by C++

    return color