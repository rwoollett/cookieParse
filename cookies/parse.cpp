#include "parse.h"

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>

namespace py = pybind11;
namespace py = pybind11;
using namespace py::literals;

namespace Cookies
{
  std::unordered_map<std::string, std::string> cookie_map(const std::string &raw_cookie)
  {
    std::unordered_map<std::string, std::string> cookie_map;
    try
    {
      // Initialize the Python interpreter
      py::scoped_interpreter guard{};

      // Import the `http.cookies` module
      py::module httpCookies = py::module::import("http.cookies");

      // Create a SimpleCookie object
      py::object SimpleCookie = httpCookies.attr("SimpleCookie")();
      SimpleCookie.attr("load")(raw_cookie);

      // Access the items in the SimpleCookie
      // py::dict cookie_items = SimpleCookie.attr("items")();
      py::dict cookie_items = SimpleCookie.attr("items")(); // Get items() method result
      // py::dict cookie_items
      auto message = "Hello, {sessionid}! The answer is {username}"_s.format(**cookie_items);
      std::cout << message << std::endl;

      // Iterate through the items
      for (auto item : cookie_items)
      {
        py::handle key = item.first;     // Cookie name
        py::handle morsel = item.second; // Morsel object

        std::string key_str = py::str(key);
        // Extract Morsel attributes
        std::string value = py::str(morsel.attr("value"));
        std::string coded_value = py::str(morsel.attr("coded_value"));
        cookie_map[item.first.cast<std::string>()] = value;

        // Print the cookie details
        std::cout << "Cookie Name: " << key_str << "\n";
        std::cout << "Value: " << value << "\n";
        std::cout << "Coded Value: " << coded_value << "\n";
        std::cout << "-------------------\n";
      }
    }

    catch (py::error_already_set &e)
    {
      if (e.matches(PyExc_FileNotFoundError))
      {
        py::print("missing.txt not found");
      }
      else if (e.matches(PyExc_PermissionError))
      {
        py::print("missing.txt found but not accessible");
      }
      else
      {
        std::cerr << "Errors: " << e.what() << std::endl;
        //throw;
      }
    }
    catch (const std::exception &e)
    {
      std::cerr << "Errors: " << e.what() << std::endl;
    }

    return cookie_map;
  }
}