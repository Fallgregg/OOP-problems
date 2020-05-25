#include "Catalog.h"

Catalog::~Catalog() {
  Goods *temp;
  for (auto &it : _goods_set) {
    temp = it;
    _goods_set.erase(it);
    delete temp;
  }
}

bool Catalog::add_goods(string title) {
  for (auto &it : _goods_set) {
    if (it->get_title() == title) {
      return false;
    }
  }
  _goods_set.insert(new Goods(_curr_id++, title));
  return true;
}

Goods *Catalog::get_by_id(GoodsID id) {
  for (auto &it : _goods_set) {
    if (it->get_id() == id) {
      return it;
    }
  }

  return nullptr;
}

Goods *Catalog::get_by_title(string title) {
  for (auto &it : _goods_set) {
    if (it->get_title() == title) {
      return it;
    }
  }

  return nullptr;
}
