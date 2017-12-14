
cmake_minimum_required(VERSION 3.2)

project(platform VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} src/platform.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)

# Config.
include(CMakePackageConfigHelpers)

configure_package_config_file(
  cmake/platform-config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config.cmake"
  INSTALL_DESTINATION lib/cmake/platform
  NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config-version.cmake"
  COMPATIBILITY AnyNewerVersion)

# Export.
export(
  TARGETS platform
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-targets.cmake")

# Install.
install(TARGETS platform EXPORT platform)

install(
  EXPORT platform
  FILE platform-targets.cmake
  DESTINATION lib/cmake/platform)

install(DIRECTORY include DESTINATION include)

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/platform-config-version.cmake"
  DESTINATION lib/cmake/platform)

add_executable(${PROJECT_NAME}.example EXCLUDE_FROM_ALL example/main.cpp)

target_link_libraries(${PROJECT_NAME}.example ${PROJECT_NAME})

