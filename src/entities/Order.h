#ifndef OOP_PROBLEMS_ORDER_H
#define OOP_PROBLEMS_ORDER_H

#include <map>
#include "Goods.h"

typedef unsigned int OrderID;

enum Status {
  PROCESSING,
  PREPARED,
  COMPLETED,
};

class Order {
private:
  OrderID _id;
  Status _status;
  map<GoodsID, Quantity> _list;
public:
  Order(OrderID id, map<GoodsID, Quantity> list);

  Order(OrderID id, map<GoodsID, Quantity> list, Status status);

  ~Order();

  OrderID get_id();

  Status get_status();

  Status set_status(Status status);

  map<GoodsID, Quantity> get_list();
};

#endif //OOP_PROBLEMS_ORDER_H
