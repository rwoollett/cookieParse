cmake_minimum_required(VERSION 3.16)

# Cookies structures (to enable using cookie structures in other applications)
add_library(Cookies
  parse.cpp
  parse.h
)

target_include_directories(
  Cookies PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/..
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(Cookies PRIVATE
  pybind11::embed
)
