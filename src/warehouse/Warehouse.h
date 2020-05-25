#ifndef OOP_PROBLEMS_WAREHOUSE_H
#define OOP_PROBLEMS_WAREHOUSE_H

#include <map>
#include "../catalog/Catalog.h"
#include "../entities/Goods.h"

using namespace std;

class Warehouse {
private:
  Catalog _catalog;
  map<GoodsID, unsigned int> _accounting;

  bool check_existence(vector<GoodsID> list);

  void push_back(vector<Goods *> package);

public:
  bool push(vector<GoodsID> list);

  vector<Goods *> take(vector<GoodsID> list);
};

#endif //OOP_PROBLEMS_WAREHOUSE_H
