project(GD32C2x1_standard_peripheral LANGUAGES C CXX ASM)

# Comment-out unused source files.
add_library(GD32C2x1_standard_peripheral OBJECT
	${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_adc.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_cmp.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_crc.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_dbg.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_dma.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_exti.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_fmc.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_fwdgt.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_gpio.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_i2c.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_misc.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_pmu.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_rcu.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_rtc.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_spi.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_syscfg.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_timer.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_usart.c
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Source/gd32c2x1_wwdgt.c
    )

target_include_directories(GD32C2x1_standard_peripheral PUBLIC
    ${DRIVERS_DIR}/GD32C2x1_standard_peripheral/Include
    )

# CMSIS header only library is linked.
target_link_libraries(GD32C2x1_standard_peripheral PUBLIC CMSIS)
