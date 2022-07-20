# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu
CONSOLE_ENABLE = yes
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
ENCODER_ENABLE = no		# Enable Rotary Encoder

# additional features for ELITE-C
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no          # Audio output

CUSTOM_MATRIX = lite

DEFAULT_FOLDER = delikeeb/corki
SRC += matrix.c