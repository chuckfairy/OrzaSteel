# Jack cmake

project( orzasteel-os CXX )

cmake_minimum_required( VERSION 2.7 )

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_C_STANDARD 11 )

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
set(CMAKE_C_FLAGS "-std=c11 ${CMAKE_C_FLAGS}")


# RPATH
set( CMAKE_MACOSX_RPATH 1 )
set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )


# Main setup
set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/CMake" )

set( ORZA_DATA_PATH "${PROJECT_SOURCE_DIR}/data")


# Config

set( ORZASTEEL_VERSION "0.1.0" )

set( ORZASTEEL_ROOT_PATH "${PROJECT_SOURCE_DIR}" )
set( ORZASTEEL_SRC_PATH "${PROJECT_SOURCE_DIR}/src" )
set( ORZASTEEL_LIB_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/lib-src" )
set( ORZASTEEL_APP_PATH "${PROJECT_SOURCE_DIR}/apps" )
set( ORZASTEEL_DATA_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/data" )


# Load config file

include("${PROJECT_SOURCE_DIR}/config/config.cmake")


# CMake Config type [Linux, Pi]
# Linux default

add_definitions(-DORZASTEEL_BUILD_TYPE=${ORZASTEEL_BUILD_TYPE})

if( ORZASTEEL_BUILD_TYPE STREQUAL "" )
	set( ORZASTEEL_BUILD_TYPE "Linux" )
endif()


# Boost

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()


## Main includes

add_subdirectory( lib-src/liborza )
add_subdirectory( lib-src/liborza-qt )

add_subdirectory( src/common )

add_subdirectory( src/qt )

#add_subdirectory( test )
