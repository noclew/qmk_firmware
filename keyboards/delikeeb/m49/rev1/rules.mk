# Pointing Device Setting
# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = pmw3360

CUSTOM_MATRIX = lite
# OLED_DRIVER = SSD1306      # Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C

# WS2812_DRIVER = vendor        #RGB
SRC += matrix.c
QUANTUM_LIB_SRC += spi_master.c