cmake_minimum_required(VERSION 3.16)
project(StockBeastsSimulation)

# Set the C++ standard to C++17
#set(CMAKE_CXX_STANDARD 17)

# Add source files
set(SOURCE_FILES
    src/main.cpp
    src/Organism.cpp
    src/StockAPI.cpp
	src/Environment.cpp
)

# Include Vcpkg toolchain
set(VCPKG_ROOT "C:/vcpkg" CACHE STRING "")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Create the executable
add_executable(StockBeastsSimulation ${SOURCE_FILES})

# Set include directories
target_include_directories(StockBeastsSimulation PRIVATE "${PROJECT_SOURCE_DIR}/include")

# Link libraries
target_link_libraries(StockBeastsSimulation PRIVATE curl nlohmann_json)

# Set output directory
set_target_properties(StockBeastsSimulation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Set build type (Release or Debug)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Additional configurations for specific build types
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Add optimization flags for Release builds
    target_compile_options(StockBeastsSimulation PRIVATE -O3)
endif()

