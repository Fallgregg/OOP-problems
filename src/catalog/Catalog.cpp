#include "Catalog.h"

Catalog::Catalog() {
  _curr_id = 0;
}

Catalog::Catalog(set<string> title_set) {
  for (auto &title : title_set) {
    add_goods(title);
  }
}

Catalog::~Catalog() {
  Goods *temp;
  for (auto &goods : _goods_set) {
    temp = goods;
    _goods_set.erase(goods);
    delete temp;
  }
}

bool Catalog::add_goods(string title) {
  for (auto &goods : _goods_set) {
    if (goods->get_title() == title) {
      return false;
    }
  }
  _goods_set.insert(new Goods(_curr_id++, title));
  return true;
}

set<Goods> Catalog::get_catalog() {
  set<Goods> temp;
  for (Goods *goods : _goods_set) {
    temp.insert(Goods(goods->get_id(), goods->get_title()));
  }
  return temp;
}

Goods *Catalog::get_by_id(GoodsID id) {
  for (auto &goods : _goods_set) {
    if (goods->get_id() == id) {
      return goods;
    }
  }

  return nullptr;
}

Goods *Catalog::get_by_title(string title) {
  for (auto &goods : _goods_set) {
    if (goods->get_title() == title) {
      return goods;
    }
  }

  return nullptr;
}
