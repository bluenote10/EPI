cmake_minimum_required(VERSION 2.8)

project(EPI)

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)
#add_definitions(-DBOOST_TEST_DYN_LINK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")


enable_testing()

add_executable(Test test/interview.cpp)

target_link_libraries(
  Test
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(NAME MyTest COMMAND Test)
