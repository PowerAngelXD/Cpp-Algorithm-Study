cmake_minimum_required(VERSION 3.10)

project(cppal)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_executable(cppal ${SOURCES} ${HEADERS})