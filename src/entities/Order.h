#ifndef OOP_PROBLEMS_ORDER_H
#define OOP_PROBLEMS_ORDER_H

#include "Goods.h"

typedef unsigned int OrderID; // separate type for orders IDs

enum Status {
  PROCESSING,
  PREPARED,
  COMPLETED,
};

class Order {
private:
  OrderID _id; //  property for an uniq ID of order
  Status _status; // property for order status
  map<GoodsID, Quantity> _list; // property for an order
public:
  Order(OrderID id, map<GoodsID, Quantity> list); // constructor, initializing order ID and list of goods

  Order(OrderID id, map<GoodsID, Quantity> list, Status status); // constructor, initializing order ID, list of goods and order status

  ~Order(); // destructor

  OrderID get_id(); // method for getting order ID

  Status get_status(); // method for getting order status

  Status set_status(Status status); // method for setting order status

  map<GoodsID, Quantity> get_list(); // method for getting list of goods in the order
};

#endif //OOP_PROBLEMS_ORDER_H
