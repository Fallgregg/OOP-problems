#include "Catalog.h"

Catalog::Catalog() {
  _curr_id = 0;
}

Catalog::Catalog(vector<string> titles) {
  _curr_id = 0;

  for (auto &title : titles) {
    add_goods(title);
  }
}

Catalog::~Catalog() {
  for (auto &goods : _goods_list) {
    delete goods;
  }

  _goods_list.clear();
}

bool Catalog::add_goods(string title) {
  for (auto &goods : _goods_list) {
    if (goods->get_title() == title) {
      return false;
    }
  }
  _goods_list.push_back(new Goods(_curr_id++, title));
  return true;
}

vector<Goods> Catalog::get_catalog() {
  vector<Goods> temp;
  for (Goods *goods : _goods_list) {
    temp.emplace_back(goods->get_id(), goods->get_title());
  }
  return temp;
}

Goods *Catalog::get_by_id(GoodsID id) {
  for (auto &goods : _goods_list) {
    if (goods->get_id() == id) {
      return goods;
    }
  }

  return nullptr;
}

Goods *Catalog::get_by_title(string title) {
  for (auto &goods : _goods_list) {
    if (goods->get_title() == title) {
      return goods;
    }
  }

  return nullptr;
}
