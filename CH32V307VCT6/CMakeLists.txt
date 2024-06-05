set(SRC_DIRS BSP Core Peripheral/inc Peripheral/src User)

set(_lib_project CH32V307VCT6)

foreach(dir IN LISTS SRC_DIRS)
	aux_source_directory(${dir} SRC)
endforeach()
# message(STATUS ${SRC})

add_library(${_lib_project} STATIC ${SRC} )
# target_sources(${_lib_project} INTERFACE ${SRC} )
target_include_directories(${_lib_project}  PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/BSP
	${CMAKE_CURRENT_LIST_DIR}/Core
    ${CMAKE_CURRENT_LIST_DIR}/Debug
	${CMAKE_CURRENT_LIST_DIR}/Peripheral/inc
	${CMAKE_CURRENT_LIST_DIR}/User
)

add_library(${_lib_project}_debug INTERFACE)
target_sources(${_lib_project}_debug INTERFACE
    Debug/debug.c
)

target_include_directories(${_lib_project}_debug INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/Debug
)

function(_ch32v307vct6_target target mcu)
    message(STATUS "ch32v307vct6: Building ${target} for ${mcu}")
	
    cmake_parse_arguments(arg "DEBUG" "" "" ${ARGN})
	message(STATUS "arg_DEBUG=${arg_DEBUG}")
	
	# TODO
	# for the chips that support multiple flash+sram configurations, we don't support them
    if(${mcu} MATCHES "^ch32v303[acfgjkrtvwz]b[mprtu][673d]$")
        set(FLASH_SIZE "128K")
        set(RAM_SIZE "32K")
    elseif(${mcu} MATCHES "^ch32v307[acfgjkrtvwz]c[mprtu][673d]$")
        set(FLASH_SIZE 256K)
        set(RAM_SIZE 64K)
    else()
        message(FATAL_ERROR "Unsupported mcu: ${mcu}")
    endif()

    message(STATUS "ch32v30x: Flash size: ${FLASH_SIZE}; RAM size: ${RAM_SIZE}")

    configure_file(
        ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Ld/Link.ld.in
        ${CMAKE_CURRENT_BINARY_DIR}/Link.ld
        @ONLY
    )

    if(${mcu} MATCHES "^ch32v303")
        target_sources(${target} PRIVATE
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Startup/startup_ch32v30x_D8.S
        )
        target_compile_definitions(${target} PRIVATE
            "-DCH32V30x_D8=1"
        )
    else()
        target_sources(${target} PRIVATE
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/Startup/startup_ch32v30x_D8C.S
        )
        target_compile_definitions(${target} PRIVATE
            "-DCH32V30x_D8C=1"
        )
    endif()

    set(march "rv32imafc")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "12.0.0")
        set(march "${march}_zicsr")
    endif()

    target_compile_options(${target} PRIVATE
        -march=${march}
        -mabi=ilp32f
    )

    target_link_options(${target} PRIVATE
        -march=${march}
        -mabi=ilp32f
        -T${CMAKE_CURRENT_BINARY_DIR}/Link.ld
    )
	
	target_link_libraries(${target}
        ${_lib_project}
    )

    if(arg_DEBUG)
        target_link_libraries(${target}
            ${_lib_project}_debug
        )
    endif()
endfunction()
