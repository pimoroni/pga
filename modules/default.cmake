if(NOT DEFINED PIMORONI_PICO_PATH)
set(PIMORONI_PICO_PATH ../pimoroni-pico)
endif()
include(${CMAKE_CURRENT_LIST_DIR}/../pimoroni_pico_import.cmake)

include_directories(${PIMORONI_PICO_PATH}/micropython)

list(APPEND CMAKE_MODULE_PATH "${PIMORONI_PICO_PATH}/micropython")
list(APPEND CMAKE_MODULE_PATH "${PIMORONI_PICO_PATH}/micropython/modules")

# Allows us to find /pga/modules/c/<module>/micropython
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(c/example/micropython)

include(micropython-common)

if(PICO_BOARD STREQUAL "pga2350")
enable_ulab()
endif()

# C++ Magic Memory
# include(cppmem/micropython)

# Disable build-busting C++ exceptions
include(micropython-disable-exceptions)