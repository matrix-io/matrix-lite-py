from halSwig import imu, imu_values
from halSwig import uv, uv_values
from halSwig import humidity, humidity_values
from halSwig import pressure, pressure_values
      
# Print statement for each sensor
def sensorPrint(self):
    # return "Yaw %d" % (self.yaw)
    return "NOT YET IMPLEMENTED. DO THIS CMON WE WAITING!"

# IMU
imu_values.__str__ = sensorPrint
imu = imu()

# UV
uv = uv()
uv.__str__ = sensorPrint

# Humidity
humidity = humidity()
humidity.__str__ = sensorPrint

# Pressure
pressure = pressure()
pressure.__str__ = sensorPrint