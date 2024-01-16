cmake_minimum_required(VERSION 3.5)

project(carrier_pigeon VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Add build directory to include path

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network Core)

include_directories(include)

file(GLOB SOURCES src/*.cpp src/*.ui)
file(GLOB HEADERS include/*.h)

# Settings for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_compile_definitions(APP_NAME="${PROJECT_NAME}") # Name in Windows properties
    configure_file(version.rc.in version.rc) # Set VERSIONINFO file

    # Set Windows resources
    enable_language("RC")
    set(WIN32_RESOURCES ${PROJECT_BINARY_DIR}/version.rc)
endif()

# Settings for Mac OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0") # Set minimum target to Mac OS Big Sur
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${WIN32_RESOURCES})

configure_file(config.h.in config.h) # Set config header file

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Network Qt6::Core)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "Carrier Pigeon"
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
)
