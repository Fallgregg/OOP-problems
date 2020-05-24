#include "Client.h"

Client::Client(std::string login) {
  _login = login;
}

std::string Client::get_login() {
  return _login;
}
