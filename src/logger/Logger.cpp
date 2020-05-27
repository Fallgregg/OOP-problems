#include "Logger.h"

Logger::Logger() {
  vector<string> base_list = {"Door", "Window", "Wallpapers"};
  _cms = new CMS(base_list);
}

Logger::~Logger() {
  delete _cms;
}

void Logger::add_goods(string title) {
  if (_cms->add_goods(title)) {
    cout << "New item was successfully added.\n";
  } else {
    cout << "New item was not added!\n";
  }
}

void Logger::get_catalog() {
  cout << "\nCatalog of goods:\n";
  vector<Goods> catalog = _cms->get_catalog();
  for (auto &good: catalog) {
    cout << good.get_id() << ":" << good.get_title() << endl;
  }
}

void Logger::get_shortages() {
  cout << "\nA list of goods to buy:\n";
  map<GoodsID, Quantity> shortages = _cms->get_shortages();
  for (auto &it : shortages) {
    GoodsID goods_id = it.first;
    Quantity goods_quantity = it.second;
    cout << goods_id << ":" << goods_quantity << endl;
  }
}

void Logger::get_reservations() {
  cout << "\nA list of reservations:\n";
  map<GoodsID, Quantity> reservation = _cms->get_reservations();
  for (auto &it : reservation) {
    GoodsID goods_id = it.first;
    Quantity goods_quantity = it.second;
    cout << goods_id << ":" << goods_quantity << endl;
  }
}

void Logger::get_order_list() {
  cout << "\nOrder list: \n";
  vector<Order *> order_list = _cms->get_order_list();
  for (auto &order : order_list) {
    cout << order->get_id() << ":" << order->get_status();
  }
}

void Logger::get_order_info(OrderID id) {
  Order *order = _cms->get_order_info(id);
  if (order != nullptr) {
    cout << order->get_id() << ":" << order->get_status() << endl;
    cout << "\nList of goods:\n";
    for (auto &it : order->get_list()) {
      cout << it.first << ":" << it.second << endl;
    }
  } else {
    cout << "\nOrder is not completed.\n";
  }
}

void Logger::add_stock(map<GoodsID, Quantity> list) {
  cout << "Goods to add to warehouse:\n";
  for (auto &it : list) {
    cout << it.first << ":" << it.second << endl;
  }

  if (!_cms->add_stock(list)) {
    cout << "Good was not added to the catalog.\n";
  } else {
    cout << "Good was added to the warehouse.\n";
  }
}

void Logger::make_order(map<GoodsID, Quantity> list) {
  cout << "Goods to make an order: \n";
  for (auto &it : list) {
    cout << it.first << ":" << it.second << endl;
  }

  int id = _cms->make_order(list);
  if (id == -1) {
    cout << "\nGood was not added to the catalog.\n";
  } else {
    cout << "Order was created.\nID : " << id << endl;
  }
}

void Logger::collect_order(OrderID id) {
  bool result = _cms->collect_order(id);
  if (result) {
    cout << "Order " << id << " : PREPARED.\n";
  } else {
    cout << "\nThere is no order to collect, no such order or no needed quantity on warehouse.\n";
  }
}

void Logger::get_order(OrderID id) {
  Order *order = _cms->get_order(id);

  if (order != nullptr) {
    cout << order->get_id() << ":" << order->get_status() << endl;
    cout << "\nList of goods:\n";
    for (auto &it : order->get_list()) {
      cout << it.first << ":" << it.second << endl;
    }
  } else {
    cout << "\nNo order had been found or Order is not prepared.\n";
  }
}
