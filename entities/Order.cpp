#include "Order.h"

Order::Order(std::vector<Goods> list) {
  _status = UNAVAILABLE;
  _list = list;
}

std::vector<Goods> Order::get_list() {
  return _list;
}
