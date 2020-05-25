#ifndef OOP_PROBLEMS_CMS_H
#define OOP_PROBLEMS_CMS_H

#include <map>
#include <vector>
#include "../entities/Goods.h"
#include "../entities/Order.h"
#include "../warehouse/Warehouse.h"

class CMS {
private:
  OrderID _curr_id;

  Warehouse _warehouse;

  map<GoodsID, Quantity> _shortages;
  map<GoodsID, Quantity> _reservations;

  vector<Order *> _orders;

  Quantity get_reserved_goods_quantity(GoodsID id);

  bool reserve(GoodsID id, Quantity quantity);

  Order *get_order_by_id(OrderID id);

  Order *get_order_copy(Order *order);

public:
  CMS();

  ~CMS();

  set<Goods> get_catalog();

  map<GoodsID, Quantity> get_shortages();

  map<GoodsID, Quantity> get_reservations();

  Order *get_order_info(OrderID id);

  bool add_stock(map<GoodsID, Quantity> list);

  int make_order(map<GoodsID, Quantity> list);

  bool collect_order(OrderID id);

  Order *get_order(OrderID id);
};

#endif //OOP_PROBLEMS_CMS_H
