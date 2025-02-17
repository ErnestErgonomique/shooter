cmake_minimum_required(VERSION 3.5)

project(PathPuzzle CXX)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(ASSET_DIR "${CMAKE_SOURCE_DIR}/assets")

file(GLOB SOURCES "${SRC_DIR}/*.cpp")
file(COPY ${ASSET_DIR} DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(shooter ${SOURCES})
target_include_directories(shooter PRIVATE ${INCLUDE_DIR})
target_link_libraries(shooter sfml-graphics)
target_link_libraries(shooter sfml-audio)
