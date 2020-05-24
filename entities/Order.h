#ifndef OOP_PROBLEMS_ORDER_H
#define OOP_PROBLEMS_ORDER_H

#include "Goods.h"
#include <string>
#include <vector>

enum Status {
  AVAILABLE,
  UNAVAILABLE,
};

class Order {
private:
  Status _status;
  std::vector<Goods> _list;
public:
  Order(std::vector<Goods> _list);

  std::vector<Goods> get_list();
};

#endif //OOP_PROBLEMS_ORDER_H
