#ifndef OOP_PROBLEMS_WAREHOUSE_H
#define OOP_PROBLEMS_WAREHOUSE_H

#include "../catalog/Catalog.h"
#include "../entities/Goods.h"

using namespace std;

class Warehouse {
private:
  Catalog *_catalog; // instance of Catalog class
  map<GoodsID, Quantity> _accounting; // property for accounting of goods in the stock
public:
  Warehouse(); // constructor

  Warehouse(vector<string> titles); // constructor, initializing list of titles

  Warehouse(map<string, Quantity> list); // constructor, initializing list of goods with quantity

  ~Warehouse(); // destructor

  bool is_exist(GoodsID goods_id); // method for checking if good exist by id

  bool is_exist(map<GoodsID, Quantity> list); // method for checking if good axist by list of goods in the order

  bool add_goods(string title);

  Quantity get_goods_quantity(GoodsID id); // method for getting quantity of good by ID

  vector<Goods> get_catalog(); // method for getting catalog of goods

  Goods *get_goods_by_id(GoodsID id); // method for getting goods by ID

  Goods *get_goods_by_title(string title); // method for getting goods by title

  bool push(map<GoodsID, Quantity> list); // method for adding items to the stock

  bool take(map<GoodsID, Quantity> list); // method for finding items in the stock
};

#endif //OOP_PROBLEMS_WAREHOUSE_H
