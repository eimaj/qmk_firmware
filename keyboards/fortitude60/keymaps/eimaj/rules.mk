RGBLIGHT_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

# Bootloader
#     This definition is optional, and if your keyboard supports multiple bootloaders of
#     different sizes, comment this out, and the correct address will be loaded
#     automatically (+60). See bootloader.mk for all options.
BOOTLOADER = caterina