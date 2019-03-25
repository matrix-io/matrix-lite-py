from matrix_lite import sensors
import time

#  Sensors will update with each .read() call
while True:
    # Each .read() returns a dictionary
    print(sensors.imu.read())
    print(sensors.uv.read())
    print(sensors.humidity.read())
    print(sensors.pressure.read())

    time.sleep(0.50)


# setInterval(function(){
#   imu = matrix.imu.read();
#   uv = matrix.uv.read();
#   humidity = matrix.humidity.read();
#   pressure = matrix.pressure.read();
  
#   console.log(imu, uv, humidity, pressure);
# },50);