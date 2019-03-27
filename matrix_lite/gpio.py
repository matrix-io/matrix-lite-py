from halSwig import gpio as _gpio

_gpio = _gpio()

# Set a pin as input or output
def setMode(pin, mode):
    if(mode == 0 or str(mode).lower() == 'input'):
        mode = 0
    elif(mode == 1 or str(mode).lower() == 'output'):
        mode = 1
    else:
        raise Exception("led.set() only accepts a value or list of values from: strings, tuples & dicts")

    _gpio.setMode(pin, mode)

# Set a pin as I/O or PWM
def setFunction(pin, mode):
    if(mode == 0 or str(mode).lower() == 'digital') :
        mode = 0
    elif(mode == 1 or str(mode).lower() == 'pwm'):
        mode = 1
    else: 
        raise Exception('Did not specify mode as "I/O" or "PWM"\n')

    _gpio.setFunction(pin, mode)

# Read digital pin value
def getDigital(pin):
  return _gpio.getValue(pin)

# Set digital pin value
def setDigital(pin, mode):
    if(mode == 0 or str(mode).lower() == 'off'):
        mode = 0
    elif(mode == 1 or str(mode).lower() == 'on'):
        mode = 1
    else: 
        raise Exception('Did not specify value as "on" or "off"\n')

    return _gpio.setDigital(pin, mode)

# Set PWM value
def setPWM(config):
    return _gpio.setPWM(config["pin"], config["percentage"], config["frequency"])

# Set Servo Angle
def setServoAngle(config):
    # min_pulse_ms is the minimum pulse width for a PWM wave in milliseconds
    return _gpio.setServoAngle(config["pin"], config["angle"], config["min_pulse_ms"])