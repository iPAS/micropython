set(SDKCONFIG_DEFAULTS
    boards/sdkconfig.base
    boards/sdkconfig.240mhz
    boards/Rapbit32/sdkconfig.board
)

if(NOT MICROPY_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_BOARD_DIR}/manifest.py)
endif()
