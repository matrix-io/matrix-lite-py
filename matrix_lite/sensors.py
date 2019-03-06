from halSwig import imu, uv, humidity, pressure

# imu_struct

def sensorPrint(self):
    return "Yaw %d" % (self.read().yaw)

imu.__str__ = sensorPrint



imu = imu()

uv = uv()
humidity = humidity()
pressure = pressure()