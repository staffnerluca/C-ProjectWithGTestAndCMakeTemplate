cmake_minimum_required(VERSION 3.5)

# Set the project name
project(resh)

# Add header files in the lib
include_directories(lib) 

# Include GoogleTest
add_subdirectory(googletest)
include_directories(googletest/include)

# Set the directory containing test files
set(TEST_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/reshTestFiles")

# Add an executable with the main sources
set(SOURCES
    src/main.cpp
    src/lexer.cpp
)

add_executable(run_opt ${SOURCES})
target_include_directories(run_opt PRIVATE ${PROJECT_SOURCE_DIR}/lib)

# Enable testing for the project
enable_testing()

# Add an executable for tests and link GoogleTest
add_executable(run_opt_test
  src/lexer.cpp
  tests/lexer-test.cpp
)

target_link_libraries(run_opt_test gtest_main)
target_include_directories(run_opt_test PRIVATE ${PROJECT_SOURCE_DIR}/lib)

# Discover tests using GoogleTest
include(GoogleTest)
gtest_discover_tests(run_opt_test)
