#------------------------------------------------------------------------------
# CMakeLists.txt
# By gnidmoo <gnidmoo@gmail.com>
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)

project(CubeLand)

#------------------------------------------------------------------------------
# Get source files
#------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCE_FILES source/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

foreach(HEADER_FILE ${HEADER_FILES})
	get_filename_component(HEADER_DIRECTORY ${HEADER_FILE} DIRECTORY)
	include_directories(${HEADER_DIRECTORY})
endforeach(HEADER_FILE)

#------------------------------------------------------------------------------
# Compiler flags
#------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfatal-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-variadic-macros")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
endif()

#------------------------------------------------------------------------------
# Packages
#------------------------------------------------------------------------------
# - SFML
#------------------------------------------------------------------------------
find_package(SFML COMPONENTS graphics system window)

include_directories(${SFML_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# - libegdt
#------------------------------------------------------------------------------
include(ExternalProject)

set(EGDT_DIR ${CMAKE_SOURCE_DIR}/external/libegdt/src/libegdt)

ExternalProject_Add(libegdt
					PREFIX external/libegdt
					GIT_REPOSITORY http://github.com/Quent42340/libegdt.git
					INSTALL_DIR external/include
					INSTALL_COMMAND sh -c "echo 'n' | ln -si `find ${EGDT_DIR}/* -name *.hpp` ${CMAKE_SOURCE_DIR}/external/include > /dev/null 2>&1")

include_directories(external/include)

link_directories(external/libegdt/src/libegdt-build)

#------------------------------------------------------------------------------
# Add executable
#------------------------------------------------------------------------------
add_executable(${CMAKE_PROJECT_NAME}
			   ${SOURCE_FILES})

add_dependencies(${CMAKE_PROJECT_NAME} libegdt)

#------------------------------------------------------------------------------
# Link options
#------------------------------------------------------------------------------
target_link_libraries(${CMAKE_PROJECT_NAME}
					  ${SFML_LIBRARIES}
					  egdt)
