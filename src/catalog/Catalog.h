#ifndef OOP_PROBLEMS_CATALOG_H
#define OOP_PROBLEMS_CATALOG_H

#include "../entities/Goods.h"

using namespace std;

class Catalog {
private:
  GoodsID _curr_id; // property of current ID of goods
  vector<Goods *> _goods_list; // property of list of all goods in the stock
public:
  Catalog(); // constructor

  Catalog(vector<string> titles); // constructor, initializing list of titles

  ~Catalog(); // destructor

  bool add_goods(string title); // method for getting new good to the catalog

  vector<Goods> get_catalog(); // method for getting catalog of goods in the stock

  Goods *get_by_id(GoodsID id); // method for getting goods by ID

  Goods *get_by_title(string title); // method for getting goods by title
};

#endif //OOP_PROBLEMS_CATALOG_H
