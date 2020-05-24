#ifndef OOP_PROBLEMS_GOODS_H
#define OOP_PROBLEMS_GOODS_H

#include <string>

class Goods {
private:
  std::string _title;
public:
  Goods(std::string title);

  std::string get_title();
};

#endif //OOP_PROBLEMS_GOODS_H
