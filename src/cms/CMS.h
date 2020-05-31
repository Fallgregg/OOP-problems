#ifndef OOP_PROBLEMS_CMS_H
#define OOP_PROBLEMS_CMS_H

#include "../entities/Goods.h"
#include "../entities/Order.h"
#include "../warehouse/Warehouse.h"

class CMS {
private:
  OrderID _curr_id; // property for current ID of order

  Warehouse *_warehouse; // instance of Warehouse class

  map<GoodsID, Quantity> _shortages; // property for shortage goods
  map<GoodsID, Quantity> _reservations; // property for reserved goods

  vector<Order *> _orders; // property for all orders

  Quantity get_reserved_goods_quantity(GoodsID id); // method for getting reserved goods quantity

  bool reserve(GoodsID id, Quantity quantity); // method for reserving goods

  Order *get_order_by_id(OrderID id); // method for getting order by ID

  Order *get_order_copy(Order *order); // method for getting cope of order

public:
  CMS(); // constructor

  CMS(vector<string> titles); // constructor, initializing list of titles

  CMS(map<string, Quantity> list); // constructor, initializing list of titles with quantity

  ~CMS(); // destructor

  bool add_goods(string title); // method for checking if item was added

  vector<Goods> get_catalog(); // method for getting catalog of goods in the stock

  map<GoodsID, Quantity> get_shortages(); // method for getting list if shortage goods

  map<GoodsID, Quantity> get_reservations(); // method for getting list of reserved goods

  vector<Order *> get_order_list(); // method for getting list of orders

  Order *get_order_info(OrderID id); // method for getting information of order by ID

  bool add_stock(map<GoodsID, Quantity> list); // method for adding items to buy to the stock

  int make_order(map<GoodsID, Quantity> list); // method for making an order

  bool collect_order(OrderID id); // method for collecting an order

  Order *get_order(OrderID id); // method for getting an order

  Goods *get_good_by_id(GoodsID id); // method for getting goods by IDs

  Goods *get_good_by_title(string title); // method for getting goods by title

};

#endif //OOP_PROBLEMS_CMS_H
