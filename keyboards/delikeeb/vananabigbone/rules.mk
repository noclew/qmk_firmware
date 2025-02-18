# -----595 shifter
CUSTOM_MATRIX = lite
SRC += matrix.c
SPI_DRIVER_REQUIRED = yes

# -----OLED 1306
OLED_ENABLE = yes
# Enable Support for SSD1306 or SH1106 OLED Displays; Communicating over I2C
OLED_DRIVER = ssd1306
   