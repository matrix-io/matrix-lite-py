from halSwig import imu, imu_values
from halSwig import uv, uv_values
from halSwig import humidity, humidity_values
from halSwig import pressure, pressure_values
      
# Printing for a sensor's read method
def valuePrint(obj):
    output = ""

    for value in dir(obj): 
        if not value.startswith('__') and value != "this":
            output = ("{}{} {}\n".format(output, value, getattr(obj, value)))
                
    return output

# IMU
imu_values.__str__ = valuePrint
imu = imu()

# UV
uv_values.__str__ = valuePrint
uv = uv()

# Humidity
humidity_values.__str__ = valuePrint
humidity = humidity()

# Pressure
pressure_values.__str__ = valuePrint
pressure = pressure()