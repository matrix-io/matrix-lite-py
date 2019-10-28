import _matrix_hal as hal

__name__ = "matrix_lite"
__all__ = ["led","sensors","gpio","info"]

# Exported variables
gpio = hal.gpio()
info = hal.info()
import matrix_lite.led as led
import matrix_lite.sensors as sensors