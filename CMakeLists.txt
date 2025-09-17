cmake_minimum_required(VERSION 3.16)
project(
  CookieProject VERSION 1.0
  DESCRIPTION "Cookie structures."
  LANGUAGES CXX C
)

# set everything up for c++ 20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/home/rwlltt/.local/lib/python3.8/site-packages/pybind11/share/cmake/pybind11")

find_package(pybind11 REQUIRED)

add_subdirectory(cookies)

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)

  include(FetchContent)
  FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
  )
  FetchContent_MakeAvailable(nlohmann_json)
  target_link_libraries(Cookies PUBLIC nlohmann_json::nlohmann_json)

  add_subdirectory(test)
endif()
