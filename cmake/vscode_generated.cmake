# This is converter generated file, and shall not be touched by user
#
# Use CMakeLists.txt to apply user changes
cmake_minimum_required(VERSION 3.22)

# Core MCU flags, CPU, instruction set and FPU setup
set(cpu_PARAMS ${cpu_PARAMS}
    -mthumb

    # Other parameters
    # -mcpu, -mfloat, -mfloat-abi, ...
    -mcpu=cortex-m4
	-mfpu=fpv4-sp-d16
	-mfloat-abi=hard
	
)

# Linker script
set(linker_script_SRC ${linker_script_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/STM32F303RETX_FLASH.ld
)

file(GLOB src_files "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/STM32F3xx_HAL_Driver/Src/*.c")

# Sources
set(sources_SRCS ${sources_SRCS}
	#cpp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/Pin.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/System.cpp
	# c
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/syscalls.c
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/sysmem.c
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/system_stm32f3xx.c
	${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/Startup/startup_stm32f303retx.s
	${src_files}
)

# Include directories
set(include_c_DIRS ${include_c_DIRS}
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/CMSIS/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/CMSIS/Device/ST/STM32F3xx/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/STM32F3xx_HAL_Driver/Inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/STM32F3xx_HAL_Driver/Inc/Legacy"
)

set(include_cxx_DIRS ${include_cxx_DIRS}
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3"
	"${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st"
	"${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/interfaces"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/CMSIS/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/CMSIS/Device/ST/STM32F3xx/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/STM32F3xx_HAL_Driver/Inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/stm32Libs/F3/st/STM32F3xx_HAL_Driver/Inc/Legacy"
)
set(include_asm_DIRS ${include_asm_DIRS}
    
)

# Symbols definition
set(symbols_c_SYMB ${symbols_c_SYMB}
					"PLATFORM_STM32F3"
					"STM32F303xE"
					"STM32"
					"STM32F3"
					"STM32F303RETx"
					"NUCLEO_F303RE"
)

set(symbols_cxx_SYMB ${symbols_cxx_SYMB}
					"PLATFORM_STM32F3"
					"STM32F303xE"
					"STM32"
					"STM32F3"
					"STM32F303RETx"
					"NUCLEO_F303RE"
)
set(symbols_asm_SYMB ${symbols_asm_SYMB}
    
)

# Link directories
set(link_DIRS ${link_DIRS}
    
)

# Link libraries
set(link_LIBS ${link_LIBS}
    
)

# Compiler options
set(compiler_OPTS ${compiler_OPTS})

# Linker options
set(linker_OPTS ${linker_OPTS})
