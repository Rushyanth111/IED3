cmake_minimum_required(VERSION 3.0.0)
project(ID3_EDIT VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/Id3v1.cpp
    ${PROJECT_SOURCE_DIR}/src/Id3v2.cpp
)
add_executable(ID3_EDIT main.cpp ${SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/include/Args)
include_directories(${PROJECT_SOURCE_DIR}/include/tclap)
include_directories(${LOGGO_INCLUDE_DIR})

target_link_libraries(ID3_EDIT)