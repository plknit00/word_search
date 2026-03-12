cmake_minimum_required(VERSION 3.18)

project(word_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(word_search_test
test.cc
word_search.cc
)

target_include_directories(word_search_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(word_search_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(word_search_test)