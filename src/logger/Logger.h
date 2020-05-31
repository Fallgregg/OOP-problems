#ifndef OOP_PROBLEMS_LOGGER_H
#define OOP_PROBLEMS_LOGGER_H

#include "../cms/CMS.h"
#include "../entities/Goods.h"
#include "../entities/Order.h"
#include "../warehouse/Warehouse.h"

class Logger {
private:
  CMS *_cms; // instance for CMS class
public:
  Logger(); // constructor

  ~Logger(); // destructor

  void add_goods(string title); // method for printing info about adding new item to the stock

  void get_catalog(); // method for printing catalog of goods

  void get_shortages(); // method for printing shortage goods

  void get_reservations(); // method for printing list of reservations

  void get_order_list(); // method for printing list of orders

  void get_order_info(OrderID id); // method for printing information about order

  void get_good_by_id(GoodsID id); // method for printing goods by ID

  void get_status(OrderID id); // method for printing goods status

  void get_good_by_title(string title); // method for printing goods by title

  void add_stock(map<GoodsID, Quantity> list); // method for printing info about adding shortages to the stock

  void make_order(map<GoodsID, Quantity> list); // method for printing info about making order

  void collect_order(OrderID id); // method for printing info about collecting order

  void get_order(OrderID id); // method for printing info about getting order
};

#endif //OOP_PROBLEMS_LOGGER_H
