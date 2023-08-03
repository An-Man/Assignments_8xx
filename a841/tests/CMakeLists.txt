cmake_minimum_required(VERSION 3.15)

project(cont_test)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} cont_test.cpp)

# target_include_directories(${PROJECT_NAME} PUBLIC include)
# target_link_libraries(${PROJECT_NAME} PUBLIC container)