cmake_minimum_required(VERSION 3.30.5)

set(This labor7_2test)

set(Sources
   labor7_2test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    laborw7_2
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
