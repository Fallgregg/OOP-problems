#include "Goods.h"

Goods::Goods(GoodsID id, string title) {
  _id = id;
  _title = title;
}

GoodsID Goods::get_id() {
  return _id;
}

string Goods::get_title() {
  return _title;
}
