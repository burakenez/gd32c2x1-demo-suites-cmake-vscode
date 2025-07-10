project(GD32C231C_EVAL LANGUAGES C CXX ASM)

add_library(GD32C231C_EVAL OBJECT
    ${DRIVERS_DIR}/BSP/GD32C231C_EVAL/gd32c231c_eval.c
    )

target_include_directories(GD32C231C_EVAL PUBLIC
    ${DRIVERS_DIR}/BSP/GD32C231C_EVAL
    )

target_link_libraries(GD32C231C_EVAL PUBLIC GD32C2x1_standard_peripheral)
