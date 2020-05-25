#ifndef OOP_PROBLEMS_WAREHOUSE_H
#define OOP_PROBLEMS_WAREHOUSE_H

#include <map>
#include <string>
#include "../catalog/Catalog.h"
#include "../entities/Goods.h"

using namespace std;

class Warehouse {
private:
  Catalog _catalog;
  map<GoodsID, Quantity> _accounting;
public:
  // TODO add goods
  Warehouse();

  Warehouse(set<string> title_set);

  ~Warehouse();

  bool is_exist(GoodsID goods_id);

  bool is_exist(map<GoodsID, Quantity> list);

  Quantity get_goods_quantity(GoodsID id);

  set<Goods> get_catalog();

  bool push(map<GoodsID, Quantity> list);

  bool take(map<GoodsID, Quantity> list);
};

#endif //OOP_PROBLEMS_WAREHOUSE_H
