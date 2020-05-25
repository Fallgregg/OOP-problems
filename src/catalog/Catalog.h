#ifndef OOP_PROBLEMS_CATALOG_H
#define OOP_PROBLEMS_CATALOG_H

#include <set>
#include <string>
#include <vector>
#include "../entities/Goods.h"

using namespace std;

class Catalog {
private:
  GoodsID _curr_id = 0;
  set<Goods *> _goods_set;
public:
  ~Catalog();

  bool add_goods(string title);

  Goods *get_by_id(GoodsID id);

  Goods *get_by_title(string title);
};

#endif //OOP_PROBLEMS_CATALOG_H
