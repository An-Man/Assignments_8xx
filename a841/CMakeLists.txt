cmake_minimum_required(VERSION 3.15)

project(array)

# set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
# target_link_libraries(${PROJECT_NAME} PUBLIC container)