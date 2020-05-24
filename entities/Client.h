#ifndef OOP_PROBLEMS_CLIENT_H
#define OOP_PROBLEMS_CLIENT_H

#include <string>

class Client {
private:
  std::string _login;
public:
  Client(std::string title);

  std::string get_login();
};

#endif //OOP_PROBLEMS_CLIENT_H
