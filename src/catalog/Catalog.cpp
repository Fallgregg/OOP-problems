#include "Catalog.h"

bool Catalog::add_goods(Goods *goods) {
  for (auto &it : _goods_map) {
    if (it.second->get_title() == goods->get_title()) {
      return false;
    }
  }
  _goods_map.insert(std::pair<GoodsID, Goods *>(_curr_id++, goods));
  return true;
}

std::vector<Goods *> Catalog::get_all() {
  std::vector<Goods *> all;
  for (auto &it : _goods_map) {
    all.push_back(it.second);
  }
  return all;
}

Goods *Catalog::get_by_id(GoodsID id) {
  auto it = _goods_map.find(id);
  return it != _goods_map.end() ? it->second : nullptr;
}
