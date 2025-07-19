
def parse_cookie(raw_cookie: str) -> dict:
    from http.cookies import SimpleCookie
    cookie = SimpleCookie()
    cookie.load(raw_cookie)
    return {key: morsel.value for key, morsel in cookie.items()}
