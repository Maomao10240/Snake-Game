cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_executable(SnakeGame main.cpp snake.cpp board.cpp)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link necessary libraries (if any, for example, SDL)


enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests/main_test.cpp tests/snake_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
add_test(runTests runTests)

