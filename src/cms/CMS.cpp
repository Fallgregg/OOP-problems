#include "CMS.h"

Quantity CMS::get_reserved_goods_quantity(GoodsID id) {
  return _reservations[id];
}

bool CMS::reserve(GoodsID id, Quantity quantity) {
  _reservations[id] += quantity;
  return true;
}

Order *CMS::get_order_by_id(OrderID id) {
  for (auto &order : _orders) {
    if (order->get_id() == id) {
      return order;
    }
  }

  return nullptr;
}

Order *CMS::get_order_copy(Order *order) {
  return new Order(order->get_id(), order->get_list(), order->get_status());
}

CMS::CMS() {
  _curr_id = 0;
  _warehouse = new Warehouse();
}

CMS::CMS(vector<string> titles) {
  _curr_id = 0;
  _warehouse = new Warehouse(titles);
  vector<Goods> catalog = _warehouse->get_catalog();


  for (Goods goods : catalog) {
    _shortages[goods.get_id()] = 0;
    _reservations[goods.get_id()] = 0;
  }
}

CMS::CMS(map<string, Quantity> list) {
  _curr_id = 0;
  _warehouse = new Warehouse(list);
  vector<Goods> catalog = _warehouse->get_catalog();


  for (Goods goods : catalog) {
    _shortages[goods.get_id()] = 0;
    _reservations[goods.get_id()] = 0;
  }
}

CMS::~CMS() {
  _shortages.clear();
  _reservations.clear();

  for (Order *order : _orders) {
    delete order;
  }
  _orders.clear();
  delete _warehouse;
}

bool CMS::add_goods(string title) {
  if (_warehouse->add_goods(title)) {
    Goods *goods = _warehouse->get_goods_by_title(title);
    if (goods) {
      _shortages[goods->get_id()] = 0;
      _reservations[goods->get_id()] = 0;
      return true;
    }
  }

  return false;
}

vector<Goods> CMS::get_catalog() {
  return _warehouse->get_catalog();
}

map<GoodsID, Quantity> CMS::get_shortages() {
  return _shortages;
}

map<GoodsID, Quantity> CMS::get_reservations() {
  return _reservations;
}

vector<Order *> CMS::get_order_list() {
  vector<Order *> temp;
  for (auto &order : _orders) {
    temp.push_back(get_order_copy(order));
  }
  return temp;
}

Order *CMS::get_order_info(OrderID id) {
  Order *order = get_order_by_id(id);
  if (order != nullptr) {
    return get_order_copy(order);
  }
  return nullptr;
}

bool CMS::add_stock(map<GoodsID, Quantity> list) {
  bool push_result = _warehouse->push(list);

  if (push_result) {
    for (auto &it : list) {
      GoodsID id = it.first;
      Quantity quantity = it.second;

      int temp = (int) (_shortages[id] - quantity);
      _shortages[id] = temp < 0 ? 0 : (unsigned int) temp;
    }
  }

  return push_result;
}

int CMS::make_order(map<GoodsID, Quantity> list) {
  if (!_warehouse->is_exist(list)) {
    return -1;
  }

  for (auto &it : list) {
    GoodsID id = it.first;
    Quantity quantity = it.second;

    int available = (int) (_warehouse->get_goods_quantity(id) - get_reserved_goods_quantity(id));
    if (available < quantity) {
      _shortages[id] = quantity - available;
    }
    reserve(id, quantity);
  }

  auto *order = new Order(_curr_id++, list);
  _orders.push_back(order);

  return order->get_id();
}

bool CMS::collect_order(OrderID id) {
  Order *order = get_order_by_id(id);
  if (order != nullptr && order->get_status() == Status::PROCESSING) {
    map<GoodsID, Quantity> goods_list = order->get_list();
    for (auto &it : goods_list) {
      GoodsID goods_id = it.first;
      if (_shortages[goods_id] != 0) {
        return false;
      }
    }
    order->set_status(Status::PREPARED);
    return true;
  }
  return false;
}

Order *CMS::get_order(OrderID id) {
  Order *order = get_order_by_id(id);
  if (order != nullptr && order->get_status() == Status::PREPARED) {
    map<GoodsID, Quantity> goods_list = order->get_list();
    if (_warehouse->take(goods_list)) {
      for (auto &it : goods_list) {
        GoodsID goods_id = it.first;
        Quantity goods_quantity = it.second;
        _reservations[goods_id] -= goods_quantity;
        order->set_status(Status::COMPLETED);
        return get_order_copy(order);
      }
    }
  }

  return nullptr;
}
