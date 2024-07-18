cmake_minimum_required(VERSION 3.16.0)

project(test-circular-list)

message("start configuring ${PROJECT_NAME}")

option(DEBUG "Compile with -O0 else -O3" OFF)
option(CLEANUP "Clean up after compilation" OFF)

include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/googletest/googletest/include/)

set(MY_CXX_FLAGS
    "-Wall \
-Werror \
")

if(DEBUG)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
  message("Compiling executables with -O0 -g")
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  message("Compiling executables with -O3")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")

add_executable(
  ${PROJECT_NAME}
  ${PROJECT_SOURCE_DIR}/test_circular_list.cpp
  ${PROJECT_SOURCE_DIR}/test_circular_list.cpp
  )

target_link_libraries(${PROJECT_NAME} gtest_main)

message("end configuring ${PROJECT_NAME}")
