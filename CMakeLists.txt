# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (resh)

# add header files in the lib
include_directories(lib) 

add_subdirectory(googletest)

include_directories(googletest/include)


# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
    src/lexer.cpp
)

# Add an executable with the above sources
add_executable(run_opt ${SOURCES})

target_include_directories(run_opt
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/lib
)

enable_testing()
add_executable(run_opt_test
  src/lexer.cpp tests/lexer-test.cpp
)

target_link_libraries(run_opt_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_opt_test )