project(GD32C231G_START LANGUAGES C CXX ASM)

add_library(GD32C231G_START OBJECT
    ${DRIVERS_DIR}/BSP/GD32C231G_START/gd32c231g_start.c
    )

target_include_directories(GD32C231G_START PUBLIC
    ${DRIVERS_DIR}/BSP/GD32C231G_START
    )

target_link_libraries(GD32C231G_START PUBLIC GD32C2x1_standard_peripheral)
