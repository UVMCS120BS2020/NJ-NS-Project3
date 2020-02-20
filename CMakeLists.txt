cmake_minimum_required(VERSION 3.8)
project(NJ-NS-Project3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(NJ-NS-Project3 account.cpp account.h person.h person.cpp bank.h bank.cpp branch.h branch.cpp)
add_executable(Testing accountTester.cpp account.cpp account.h person.h person.cpp)