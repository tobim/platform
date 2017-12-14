
cmake_minimum_required(VERSION 3.2)

project(platform CXX)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} src/platform.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)

add_executable(${PROJECT_NAME}.example EXCLUDE_FROM_ALL example/main.cpp)

target_link_libraries(${PROJECT_NAME}.example ${PROJECT_NAME})
