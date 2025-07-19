cmake_minimum_required(VERSION 3.12)

add_executable(TestCookie main.cpp)

target_link_libraries(TestCookie PRIVATE
  Cookies pybind11::embed
)


