#ifndef OOP_PROBLEMS_WAREHOUSE_H
#define OOP_PROBLEMS_WAREHOUSE_H

#include <map>
#include <string>
#include <vector>
#include "../catalog/Catalog.h"
#include "../entities/Goods.h"

using namespace std;

class Warehouse {
private:
  Catalog *_catalog;
  map<GoodsID, Quantity> _accounting;
public:
  Warehouse();

  Warehouse(vector<string> titles);

  Warehouse(map<string, Quantity> list);

  ~Warehouse();

  bool is_exist(GoodsID goods_id);

  bool is_exist(map<GoodsID, Quantity> list);

  bool add_goods(string title);

  Quantity get_goods_quantity(GoodsID id);

  vector<Goods> get_catalog();

  Goods *get_goods_by_id(GoodsID id);

  Goods *get_goods_by_title(string title);

  bool push(map<GoodsID, Quantity> list);

  bool take(map<GoodsID, Quantity> list);
};

#endif //OOP_PROBLEMS_WAREHOUSE_H
