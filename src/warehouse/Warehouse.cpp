#include "Warehouse.h"

bool Warehouse::check_existence(vector<GoodsID> list) {
  for (auto it = list.begin(); it != list.end(); it++) {
    if (!_catalog.get_by_id(*it)) {
      return false;
    }
  }

  return true;
}

void Warehouse::push_back(vector<Goods *> package) {
  for (auto it = package.begin(); it != package.end(); it++) {
    Goods *goods = *it;
    _accounting[goods->get_id()] += 1;
  }
}

bool Warehouse::push(vector<GoodsID> list) {
  bool existence = check_existence(list);
  if (existence) {
    for (auto it = list.begin(); it != list.end(); it++) {
      _accounting[*it] += 1;
    }
  }

  return existence;
}

vector<Goods *> Warehouse::take(vector<GoodsID> list) {
  vector<Goods *> package;

  bool existence = check_existence(list);
  if (existence) {
    for (auto it = list.begin(); it != list.end(); it++) {
      if (_accounting[*it] > 0) {
        _accounting[*it] -= 1;
        package.push_back(_catalog.get_by_id(*it));
      } else {
        push_back(package);
        return vector<Goods *>();
      }
    }
  }

  return package;
}
