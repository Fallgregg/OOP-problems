#include "Logger.h"
//#include <iomanip>
Logger::Logger() {
  map <string , Quantity > base_list = {
      {"Mattress", 5},
      {"Blanket", 3},
      {"Pillow", 10},
      {"Rug", 25},
      {"Towel", 10},
      {"Curtains", 11},
      {"Lamp", 7},
      {"Decor", 9},
      {"Bed-linen", 5},
      {"Table", 20}
  };
  _cms = new CMS(base_list);
}

Logger::~Logger() {
  delete _cms;
}

void Logger::add_goods(string title) {
  if (_cms->add_goods(title)) {
    cout << "Successfully added.\n";
  } else {
    cout << "New item was not added!\n";
  }
}

void Logger::get_catalog() {
  cout << setw(35) << "Catalog of goods\n";
  vector<Goods> catalog = _cms->get_catalog();
  for (auto &good: catalog) {
    cout << good.get_id() << ": " << good.get_title() << endl;
  }
}

void Logger::get_shortages() {
  cout << setw(35) << "A list of shortages\n";
  map<GoodsID, Quantity> shortages = _cms->get_shortages();
  for (auto &it : shortages) {
    get_good_by_id(it.first);
    cout << ": " << it.second << endl;
  }
}

void Logger::get_reservations() {
  cout << setw(35) << "A list of reservations\n";
  map<GoodsID, Quantity> reservation = _cms->get_reservations();
  for (auto &it : reservation) {
    get_good_by_id(it.first);
    cout << ": " << it.second << endl;
  }
}

void Logger::get_order_list() {
  cout << setw(30) << "Order list \n";
  vector<Order *> order_list = _cms->get_order_list();
  for (auto &order : order_list) {
    cout << order->get_id() << ": ";
    get_status(order->get_id());
    cout << endl;
  }
}

void Logger::get_order_info(OrderID id) {
  Order *order = _cms->get_order_info(id);
  if (order != nullptr) {
    cout << endl << order->get_id() << ": ";
    get_status(id);
    cout << endl;
    cout << setw(20) << "Order\n";
    for (auto &it : order->get_list()) {
      get_good_by_id(it.first);
      cout << ": " << it.second << endl;
    }
  } else {
    cout << "\nOrder is not completed.\n";
  }
}

void Logger::get_good_by_id(GoodsID id) {
  Goods *good = _cms->get_good_by_id(id);
  if(good == nullptr) {
    cout << "Such item is not exists.\n";
  } else {
    cout << good->get_title();
  }
}

void Logger::get_status(OrderID id) {
  Order *order = _cms->get_order_info(id);
  Status status = order->get_status();
  if(status == 0) {
    cout << "PROCESSING";
  } else if (status == 1) {
    cout << "PREPARED";
  } else {
    cout << "COMPLETED";
  }
}

void Logger::get_good_by_title(string title) {
  Goods *good = _cms->get_good_by_title(title);
  if(good == nullptr) {
    cout << "Such item is not exists.\n";
  } else {
    cout << good->get_id();
  }
}

void Logger::add_stock(map<GoodsID, Quantity> list) {
  cout << setw(35) << "Goods to add to warehouse\n";
  for (auto &it : list) {
    get_good_by_id(it.first);
    cout << ": " << it.second << endl;
  }

  if (!_cms->add_stock(list)) {
    cout << "\nGood was not added to the catalog.\n";
  } else {
    cout << "\nSuccessfully added.\n";
  }
}

void Logger::make_order(map<GoodsID, Quantity> list) {
  cout << "\nOrder:\n";
  for (auto &it : list) {
    get_good_by_id(it.first);
    cout << " : " << it.second << endl;
  }

  int id = _cms->make_order(list);
  if (id == -1) {
    cout << "\nGood was not added to the catalog.\n";
  } else {
    cout << "\nCreated Successfully.\nOrder ID : " << id << endl;
  }
}

void Logger::collect_order(OrderID id) {
  bool result = _cms->collect_order(id);
  if (result) {
    cout << "\n" << id << ": PREPARED.\n";
  } else {
    cout << "\nSorry!\nThere is no order to collect, no such order or no needed quantity on warehouse.\n";
  }
}

void Logger::get_order(OrderID id) {
  Order *order = _cms->get_order(id);
  if (order != nullptr) {
    cout << order->get_id() << ": ";
    get_status(id);
    cout << endl;
    cout << "\nList of goods:\n";
    for (auto &it : order->get_list()) {
      get_good_by_id(it.first);
      cout << ": " << it.second << endl;
    }
  } else {
    cout << "\nNo order had been found or Order is not prepared.\n";
  }
}
