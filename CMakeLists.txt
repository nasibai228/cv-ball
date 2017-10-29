cmake_minimum_required(VERSION 3.8)
project(cv-ball)

set(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(SOURCE_FILES main.cpp)
add_executable(cv-ball ${SOURCE_FILES})

target_link_libraries( cv-ball ${OpenCV_LIBS} )
