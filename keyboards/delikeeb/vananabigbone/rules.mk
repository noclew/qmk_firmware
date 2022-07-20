# MCU name
MCU = atmega32u4

# Processor frequency
F_CPU = 16000000

# Bootloader selection
BOOTLOADER = atmel-dfu
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
AUDIO_ENABLE = no          # Audio output

# additional features for ELITE-C
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow

# trackball realted
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
ENCODER_ENABLE := no		# Enable Rotary Encoder
MOUSEKEY_ENABLE = yes       # Mouse keys

DEFAULT_FOLDER = delikeeb/vananabigbone/rev2
OPTS_DEF += -DENCODER_ENABLE

QUANTUM_LIB_SRC += analog.c
# SRC += opt_encoder.c
SRC += trackball.c
