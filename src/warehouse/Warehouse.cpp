#include "Warehouse.h"

Warehouse::Warehouse() {
  _catalog = Catalog();
}

Warehouse::Warehouse(set<string> title_set) {
  _catalog = Catalog(title_set);
  set<Goods> catalog = _catalog.get_catalog();

  for (Goods goods : catalog) {
    _accounting[goods.get_id()] = 0;
  }
}

Warehouse::~Warehouse() {
  _accounting.clear();
}

bool Warehouse::is_exist(GoodsID goods_id) {
  return _catalog.get_by_id(goods_id);
}

bool Warehouse::is_exist(map<GoodsID, Quantity> list) {
  for (auto &it : list) {
    if (!is_exist(it.first)) {
      return false;
    }
  }
  return true;
}

set<Goods> Warehouse::get_catalog() {
  return _catalog.get_catalog();
}

Quantity Warehouse::get_goods_quantity(GoodsID id) {
  if (is_exist(id)) {
    return _accounting[id];
  }

  return 0;
}

bool Warehouse::push(map<GoodsID, Quantity> list) {
  if (!is_exist(list)) {
    return false;
  }

  for (auto &it : list) {
    GoodsID id = it.first;
    Quantity quantity = it.second;
    _accounting[id] += quantity;
  }

  return true;
}

bool Warehouse::take(map<GoodsID, Quantity> list) {
  if (!is_exist(list)) {
    return false;
  }

  for (auto &it : list) {
    GoodsID id = it.first;
    Quantity quantity = it.second;
    if ((int) (_accounting[id] - quantity) < 0) {
      return false;
    }
  }

  for (auto &it : list) {
    GoodsID id = it.first;
    Quantity quantity = it.second;
    _accounting[id] -= quantity;
  }

  return true;
}
