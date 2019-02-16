import build.matrix as hal

# Print exported objects/functions
print(dir(hal))

# LED test
everloop = hal.everloop()
print(everloop.ledCount)

# LED Class test
led = hal.led()
led.r = 1
led.g = 0
led.b = 1
led.w = 0

everloop.ledTest(led)