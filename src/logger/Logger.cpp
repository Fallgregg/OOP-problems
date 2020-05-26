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
  cout << "\nA list of goods to buy:\n";
  map<GoodsID, Quantity> shortages = _cms.get_shortages();
  for(auto &it : shortages) {
    GoodsID goods_id = it.first;
    Quantity goods_quantity = it.second;
    cout << goods_id << ":" << goods_quantity << endl;
  }
}

void Logger::get_reservations() {
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
  Order *order = _cms.get_order_info(id);
  if(order == nullptr) {
    cout << "\nOrder is not completed.\n";
  } else {
    cout << "" << endl;
  }
}

void Logger::add_stock(map<GoodsID, Quantity> list) {
  //не могу разобраться как сделать то что ты сказал

}

void Logger::make_order(map<GoodsID, Quantity> list) {
  if((int) (_cms.make_order(list)== -1 )) {
    cout << "\nOrder was not found.\n";
  } else {
    // что тут выводить на экран?
  }
}

void Logger::collect_order(OrderID id) {
  bool order = _cms.collect_order(id);
  if (order) {
    cout << "Order " << id << " : PREPARED.\n";
  } else {
    cout << "\nThere is no order to collect.\n";
  }
}

void Logger::get_order(OrderID id) {
  vector<Order *> order = _cms.get_order_list();

  if (_cms.get_order(id)) {
    for (auto &good : order) {
      cout << good->get_id() << ":" << good->get_status() << endl;
    }
  } else {
      cout << "\nNo order had been found.\n";
    }
  }
