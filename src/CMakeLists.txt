cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0028 NEW)

# Generic test that uses conan libs
add_executable(game main.cpp)
target_compile_options(game PRIVATE $<$<BOOL:${WIN32}>:/utf-8>)
target_link_libraries(
  game PRIVATE project_options project_warnings CONAN_PKG::docopt.cpp
               CONAN_PKG::fmt CONAN_PKG::spdlog CONAN_PKG::imgui-sfml)
