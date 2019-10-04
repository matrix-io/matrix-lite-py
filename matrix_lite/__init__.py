import matrix_hal as hal

__name__ = "matrix_lite"
__all__ = ["led","sensors","gpio","info"]

gpio = hal.gpio()
info = hal.info()