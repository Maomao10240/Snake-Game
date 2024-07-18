cmake_minimum_required(VERSION 3.10)

project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(src)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link necessary libraries (if any, for example, SDL)
# Find SFML
find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

# Include SFML directories
include_directories(${SFML_INCLUDE_DIR})

# Add the executable
add_executable(SnakeGame src/main.cpp src/snake.cpp src/board.cpp)

# Link SFML libraries
target_link_libraries(SnakeGame sfml-graphics sfml-window sfml-system)





enable_testing()

# Specify the path to the Google Test libraries
#link_directories(/usr/local/opt/googletest/lib)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests/snake_test.cpp src/snake.cpp src/board.cpp)
# target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests GTest::GTest GTest::Main pthread sfml-graphics sfml-window sfml-system)

add_test(NAME runTests COMMAND runTests)

# rm -rf build
# mkdir build
# cd build
# cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/googletest ..
# make
# ctest