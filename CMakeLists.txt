
cmake_minimum_required(VERSION 3.2)

project(platform VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} src/platform.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_constexpr)
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CXX_COMPILER_ID:GNU>:-frecord-gcc-switches>")

# Config.
include(CMakePackageConfigHelpers)

configure_package_config_file(
  cmake/platform-config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config.cmake"
  INSTALL_DESTINATION lib/cmake/platform)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config-version.cmake"
  COMPATIBILITY AnyNewerVersion)

# Export.
export(
  TARGETS ${PROJECT_NAME}
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-targets.cmake"
  EXPORT_LINK_INTERFACE_LIBRARIES)

# Install.
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    COMPONENT ${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}
  FILE platform-targets.cmake
  DESTINATION lib/cmake/platform)

install(DIRECTORY include/${PROJECT_NAME} DESTINATION include)

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config-version.cmake"
  DESTINATION lib/cmake/platform)

add_executable(${PROJECT_NAME}.example EXCLUDE_FROM_ALL example/main.cpp)

target_link_libraries(${PROJECT_NAME}.example ${PROJECT_NAME})

