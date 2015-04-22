cmake_minimum_required(VERSION 2.8)
project(root)

# enable gtest
find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})
# target: *_test.cpp
file(GLOB TEST_ALL ex*/*_test.cpp)
add_executable(run_test ${TEST_ALL})
target_link_libraries(run_test
  ${GTEST_BOTH_LIBRARIES}
  -pthread
  )
