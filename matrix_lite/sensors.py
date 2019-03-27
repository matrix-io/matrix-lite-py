from halSwig import imu, imu_values
from halSwig import uv, uv_values
from halSwig import humidity, humidity_values
from halSwig import pressure, pressure_values
      
# Printing for a sensor's read method
def printValue(obj):
    output = ""

    for value in dir(obj): 
        if not value.startswith('__') and value != "this":
            output = ("{}{} {}\n".format(output, value, getattr(obj, value)))
                
    return output

# IMU
imu_values.__str__ = printValue
imu_values.__repr__ = printValue
imu = imu()

# UV
uv_values.__str__ = printValue
uv_values.__repr__ = printValue
uv = uv()

# Humidity
humidity_values.__str__ = printValue
humidity_values.__repr__ = printValue
humidity = humidity()

# Pressure
pressure_values.__str__ = printValue
pressure_values.__repr__ = printValue
pressure = pressure()