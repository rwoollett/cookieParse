#include "parse.h"

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdexcept>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

namespace Cookies
{
  std::unordered_map<std::string, std::string> cookie_map(const std::string &raw_cookie)
  {
    std::unordered_map<std::string, std::string> cookie_map;
    py::scoped_interpreter guard{};

    try
    {

      // Import the `http.cookies` module
      py::module httpCookies = py::module::import("http.cookies");
      // Create a SimpleCookie object
      py::object SimpleCookie = httpCookies.attr("SimpleCookie")();
      SimpleCookie.attr("load")(raw_cookie);

      // Access the items in the SimpleCookie
      // py::dict cookie_items = SimpleCookie.attr("items")();
      py::dict cookie_items = SimpleCookie.attr("items")(); // Get items() method result
      for (auto item : cookie_items)
      {
        py::handle key = item.first;     // Cookie name
        py::handle morsel = item.second; // Morsel object

        std::string key_str = py::str(key);
        std::string value = py::str(morsel.attr("value"));
        std::string coded_value = py::str(morsel.attr("coded_value"));
        cookie_map[item.first.cast<std::string>()] = value;
      }

    }

    catch (py::error_already_set &e)
    {
      throw std::out_of_range(e.what());
    }
    catch (const std::exception &e)
    {
      throw std::out_of_range(e.what());
    }

    return cookie_map;
  }

  std::string base64_decode(const std::string &encoded)
  {
    std::string decoded;
    py::scoped_interpreter guard{};
    try
    {
      py::module base64 = py::module::import("base64");
      py::bytes decoded_bytes = base64.attr("b64decode")(encoded);
      decoded = std::string(decoded_bytes);
    }
    catch (py::error_already_set &e)
    {
      throw std::out_of_range(e.what());
    }
    catch (const std::exception &e)
    {
      throw std::out_of_range(e.what());
    }

    return decoded;
  }

}