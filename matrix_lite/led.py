from matrix_lite import colour
from _matrix_hal import everloop

_everloop = everloop()
length = _everloop.length

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
        #Convert Hex input to tuple
        if color[0] == "#":
            try:
                rgb = color[1:]
                #6 digit Hex
                if len(rgb) == 6:
                    r, g, b = rgb[0:2], rgb[2:4], rgb[4:6]
                #3 digit Hex
                elif len(rgb) == 3:
                    r, g, b = rgb[0] * 2, rgb[1] * 2, rgb[2] * 2
                else:
                    raise ValueError()       
            
            #Invalid input given
            except:
                raise ValueError("Invalid value  provided for rgb color.")
            try:
                return tuple([int(v, 16) for v in (r, g, b)])

            except:
                return 0,0,0


        #Convet string input to tuple
        elif color in colour.COLOR_NAMES_TO_RGB.keys():
            color = colour.COLOR_NAMES_TO_RGB[color]
            return (int (color[0]), int (color[1]), int (color[2]))

        return(0,0,0)


    # Tuples are already handeled by C++

    return color
