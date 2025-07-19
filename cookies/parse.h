
#ifndef COOKIES_PARSE_H
#define COOKIES_PARSE_H

#include <unordered_map>
#include <string>

namespace Cookies
{

  std::unordered_map<std::string, std::string> cookie_map(const std::string &raw_cookie);

}
#endif // COOKIES_PARSE_H
