cmake_minimum_required(VERSION 3.16.0)

project(circular-list)

option(TESTS "compile tests" OFF)

message("start configuring ${PROJECT_NAME}")

if(TESTS)
  add_subdirectory(tests/3rdparty/googletest/)

  add_subdirectory(tests/)
endif()

message("end configuring ${PROJECT_NAME}")
