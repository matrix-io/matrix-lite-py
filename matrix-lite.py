import build.matrix as hal

# Print exported objects/functions
print(dir(hal))

# LED test
led = hal.everloop()
print(led.ledCount())

ready = input("Ready to change LEDs? ")
led.ledTest()
