#include <cookies/parse.h>
#include <string>
#include <unordered_map>
#include <iostream>

int main(int argc, char **argv)
{
  std::unordered_map<std::string, std::string> cookies;
  // Display parsed cookies
  cookies = Cookies::cookie_map("username=JohnDoe; sessionid=12345;");
  std::cout << "Cookie values" << std::endl;
  for (const auto &[key, val] : cookies)
  {
    std::cout << key << " = " << val << '\n';
  }

  return 0;
}
