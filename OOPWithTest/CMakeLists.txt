cmake_minimum_required(VERSION 3.22)

project(OOP)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(tabulate-master)
enable_testing()
add_library(my_lib OOP.cpp File.h File.cpp)
include(FetchContent)

FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0 # Или выберите нужную вам версию
)

FetchContent_MakeAvailable(gtest)
find_package(GTest REQUIRED)

add_executable(my_test my_test.cpp)
target_link_libraries(my_test GTest::GTest GTest::Main pthread my_lib)
target_include_directories(my_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tabulate-master/include
)

# Укажите тесты, которые нужно выполнить
add_test(NAME MyTest COMMAND my_test)