#ifndef OOP_PROBLEMS_LOGGER_H
#define OOP_PROBLEMS_LOGGER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "../cms/CMS.h"
#include "../entities/Goods.h"
#include "../entities/Order.h"
#include "../warehouse/Warehouse.h"

class Logger {
private:
  CMS *_cms;
public:
  Logger();

  ~Logger();

  void add_goods(string title);

  void get_catalog();

  void get_shortages();

  void get_reservations();

  void get_order_list();

  void get_order_info(OrderID id);

  void add_stock(map<GoodsID, Quantity> list);

  void make_order(map<GoodsID, Quantity> list);

  void collect_order(OrderID id);

  void get_order(OrderID id);
};

#endif //OOP_PROBLEMS_LOGGER_H
