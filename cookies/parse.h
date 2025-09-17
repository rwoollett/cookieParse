
#ifndef COOKIES_PARSE_H
#define COOKIES_PARSE_H

#include <unordered_map>
#include <string>

namespace Cookies
{

  std::unordered_map<std::string, std::string> cookie_map(const std::string &raw_cookie);
  std::string base64_decode(const std::string &encoded);


}
#endif // COOKIES_PARSE_H
