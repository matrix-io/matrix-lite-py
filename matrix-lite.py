import build.matrix as hal
from time import sleep


# Print exported objects/functions
print(dir(hal))

## LED Example ##
everloop = hal.everloop()

leds = []
for i in range(everloop.ledCount):
  led = hal.led(0,0,1,0)
  # led.r = 1
  # led.g = 0
  # led.b = 1
  # led.w = 0
  leds.append(led)

everloop.set(leds)

## IMU Example ##
# imu = hal.imu()
# while True:
#     imuData = imu.read()
#     print ("accelerometer: (xyz)",imuData.accel_x, imuData.accel_y, imuData.accel_z)
#     print ("gyroscope: (xyz)",imuData.gyro_x, imuData.gyro_y, imuData.gyro_z)
#     print ("Magnetometer:(xyz)", imuData.mag_x, imuData.mag_y, imuData.mag_z)
#     print ("Yaw Pitch Roll:", imuData.yaw, imuData.pitch, imuData.roll)
#     sleep(0.05)

## UV Example ##
uv = hal.uv()
while True:
    uvData = uv.read()
    print ("UV: ", uvData.uv)
    sleep(0.05)