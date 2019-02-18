import build.matrix as hal

# Print exported objects/functions
print(dir(hal))

# LED Example
everloop = hal.everloop()

# LED Class test
leds = []
for i in range(everloop.ledCount):
  led = hal.led(1,0,1,0)
  # led.r = 1
  # led.g = 0
  # led.b = 1
  # led.w = 0
  leds.append(led)

everloop.ledTest(leds)