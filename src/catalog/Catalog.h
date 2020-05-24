#ifndef OOP_PROBLEMS_CATALOG_H
#define OOP_PROBLEMS_CATALOG_H

#include <map>
#include <vector>
#include "../entities/Goods.h"

typedef unsigned int GoodsID;

class Catalog {
private:
  GoodsID _curr_id = 0;
  std::map<GoodsID, Goods *> _goods_map;
public:
  bool add_goods(Goods *goods);

  std::vector<Goods *> get_all();

  Goods *get_by_id(GoodsID id);
};

#endif //OOP_PROBLEMS_CATALOG_H
