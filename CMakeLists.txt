#------------------------------------------------------------------------------
# CMakeLists.txt
# By gnidmoo <gnidmoo@gmail.com>
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

project(CubeLand)

#------------------------------------------------------------------------------
# Get source files
#------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCE_FILES source/*.cpp external/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp external/*.hpp)

foreach(HEADER_FILE ${HEADER_FILES})
	get_filename_component(HEADER_DIRECTORY ${HEADER_FILE} DIRECTORY)
	include_directories(${HEADER_DIRECTORY})
endforeach(HEADER_FILE)

#------------------------------------------------------------------------------
# Add executable
#------------------------------------------------------------------------------
add_executable(${CMAKE_PROJECT_NAME}
               ${SOURCE_FILES})

#------------------------------------------------------------------------------
# Compiler flags
#------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfatal-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-variadic-macros")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc")
endif()

#------------------------------------------------------------------------------
# Packages
#------------------------------------------------------------------------------
# - SFML
#------------------------------------------------------------------------------
find_package(SFML COMPONENTS graphics system window)

include_directories(${SFML_INCLUDE_DIRS})

#------------------------------------------------------------------------------
# Link options
#------------------------------------------------------------------------------
target_link_libraries(${CMAKE_PROJECT_NAME}
					  ${SFML_LIBRARIES})

