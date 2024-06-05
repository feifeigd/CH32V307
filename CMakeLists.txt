
cmake_minimum_required(VERSION 3.20)

include(./cmake/ch32v.cmake)
include(CheckIPOSupported)

# 会查找 CMAKE_ABC_COMPILER 环境变量，ABC表示project中的语言
project(CH32V307 ASM C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
)

add_compile_options(
    -Wall
    -Wextra
    -Werror
)

add_compile_definitions(
    -DCLK_FREQ_144MHZ_HSE=1
    -DDEBUG_UART=1
)

check_ipo_supported()
set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

# 添加项目
add_subdirectory(CH32V307VCT6) # 具体的芯片型号 核心库
add_subdirectory(blink)
