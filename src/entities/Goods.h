#ifndef OOP_PROBLEMS_GOODS_H
#define OOP_PROBLEMS_GOODS_H

#include <string>

using namespace std;

typedef unsigned int GoodsID;

class Goods {
private:
  GoodsID _id;
  string _title;
public:
  Goods(GoodsID id, string title);

  GoodsID get_id();

  string get_title();
};

#endif //OOP_PROBLEMS_GOODS_H
