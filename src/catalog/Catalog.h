#ifndef OOP_PROBLEMS_CATALOG_H
#define OOP_PROBLEMS_CATALOG_H

#include <string>
#include <vector>
#include "../entities/Goods.h"

using namespace std;

class Catalog {
private:
  GoodsID _curr_id;
  vector<Goods *> _goods_list;
public:
  Catalog();

  Catalog(vector<string> titles);

  ~Catalog();

  bool add_goods(string title);

  vector<Goods> get_catalog();

  Goods *get_by_id(GoodsID id);

  Goods *get_by_title(string title);
};

#endif //OOP_PROBLEMS_CATALOG_H
