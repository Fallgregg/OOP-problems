#include "Logger.h"

Logger::Logger() {
  _cms = CMS();

}

void Logger::add_goods(string title) {
  if(_cms.add_goods(title)) {
    cout << "New item was successfully added.\n";
  } else {
    cout << "New item was not added!\n";
  }
}

void Logger::get_catalog() {
  cout << "\nCatalog of goods:\n";
  vector<Goods> catalog = _cms.get_catalog();
  for(auto &good: catalog) {
    cout << good.get_id() << ":" << good.get_title() << endl;
  }
}

void Logger::get_shortages() {
  //вывод количества для докупки
  cout << "\nA list of goods to buy:\n";
  map<GoodsID, Quantity> shortages = _cms.get_shortages();
  for(auto &it : shortages) {
    GoodsID goods_id = it.first;
    Quantity goods_quantity = it.second;
    cout << goods_id << ":" << goods_quantity << endl;
  }
}

void Logger::get_reservations() {
  //вывод коллиичества брони
  cout << "\nA list of reservations:\n";
  map<GoodsID, Quantity> reservation = _cms.get_reservations();
  for(auto &it : reservation) {
    GoodsID goods_id = it.first;
    Quantity goods_quantity = it.second;
    cout << goods_id << ":" << goods_quantity << endl;
  }
}

void Logger::get_order_list() {
  cout << "\nOrder list: \n";
  vector<Order *> order_list = _cms.get_order_list();
  for(auto &order : order_list) {
    cout << order->get_id() << ":" << order->get_status();
  }
}

void Logger::get_order_info(OrderID id) {
  if(_cms.get_order_info(id)) {
    cout << _cms.get_order_info(id) << endl;
  } else {
    cout << "\nOrder is not complited\n";
  }
}

void Logger::add_stock(map<GoodsID, Quantity> list) {
  // что тут выводить на экран?
}

void Logger::make_order(map<GoodsID, Quantity> list) {
  if((int) (_cms.make_order(list)== -1 )) {
    cout << "\nOrder was not found on warehouse\n";
  } else {
    // что тут выводить на экран?
  }
}

void Logger::collect_order(OrderID id) {
  if(_cms.collect_order(id)) {
    cout << "\nOrder status : PREPARED.\n";
  } else {
    cout << "\nOrder status : PROCESSING.\n";
  }
}

void Logger::get_order(OrderID id) {
  if(_cms.get_order(id) == nullptr) {
    cout << "\nOrder status : PREPARED.\n";
  } else {
    cout << "\nOrder status : COMPLETED.\n";
  }
}
