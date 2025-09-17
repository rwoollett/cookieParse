#include <cookies/parse.h>
#include <string>
#include <unordered_map>
#include <iostream>

int main(int argc, char **argv)
{
  std::string cookie_header = "username=JohnDoe sessionid=12345";
  std::unordered_map<std::string, std::string> cookies;
  std::string encoded = "SGVsbG8sIFdvcmxkIQ==";  // "Hello, World!" in Base64
  std::string decoded;

  // Display parsed cookies
  try {
    cookies = Cookies::cookie_map(cookie_header);
    decoded = Cookies::base64_decode(encoded);

  } catch (const std::exception &e) 
  {
    std::cerr << "Caught error: " << e.what() << std::endl;
  }

  std::cout << "Cookie values" << std::endl;
  for (const auto &[key, val] : cookies)
  {
    std::cout << key << " = " << val << '\n';
  }
  std::cout << "Decoded: " << decoded << std::endl;

  return 0;
}
