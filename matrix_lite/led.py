import colour
from matrix_hal import everloop, led

_everloop = everloop()
length = _everloop.ledCount

# Colors corrected for LED
colour.COLOR_NAME_TO_RGB["orange"] = (255, 35, 0)
colour.COLOR_NAME_TO_RGB["hotpink"] = (255, 5, 14)
colour.COLOR_NAME_TO_RGB["lightblue"] = (0, 50, 255)
colour.COLOR_NAME_TO_RGB["lightgreen"] = (20, 255, 30)

# Return RGBW dict from a string, tuple, or dict
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