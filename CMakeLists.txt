cmake_minimum_required(VERSION 3.0.0)
project(ID3_EDIT VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/ArgumentParse.cpp
    ${PROJECT_SOURCE_DIR}/src/Id3.cpp
)
add_executable(ID3_EDIT main.cpp ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


include_directories(${PROJECT_SOURCE_DIR}/include/Args)