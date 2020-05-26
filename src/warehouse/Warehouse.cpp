#include "Warehouse.h"

Warehouse::Warehouse() {
  _catalog = Catalog();
}

Warehouse::Warehouse(vector<string> titles) {
  _catalog = Catalog(titles);
  vector<Goods> catalog = _catalog.get_catalog();

  for (Goods goods : catalog) {
    _accounting[goods.get_id()] = 0;
  }
}

Warehouse::~Warehouse() {
  _accounting.clear();
}

bool Warehouse::is_exist(GoodsID goods_id) {
  return (bool) _catalog.get_by_id(goods_id);
}

bool Warehouse::is_exist(map<GoodsID, Quantity> list) {
  for (auto &it : list) {
    if (!is_exist(it.first)) {
      return false;
    }
  }
  return true;
}

bool Warehouse::add_goods(string title) {
  if (_catalog.add_goods(title)) {
    Goods *goods = _catalog.get_by_title(title);
    if (goods) {
      _accounting[goods->get_id()] = 0;
      return true;
    }
  }

  return false;
}

vector<Goods> Warehouse::get_catalog() {
  return _catalog.get_catalog();
}

Goods * Warehouse::get_goods_by_id(GoodsID id) {
  return _catalog.get_by_id(id);
}

Goods * Warehouse::get_goods_by_title(string title) {
  return _catalog.get_by_title(title);
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
