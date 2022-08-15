# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
CONSOLE_ENABLE = yes
# Build Options
#   change yes to no to disable
#


CUSTOM_MATRIX = lite

DEFAULT_FOLDER = delikeeb/corki
SRC += matrix.c