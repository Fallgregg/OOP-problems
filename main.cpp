#include "src/logger/Logger.h"

void menu();

int main() {

  Logger *test = new Logger();
  int command;
  int item_id = 0;
  int order_id = 0;
  int quantity = 0;
  bool flag = true;
  string new_item;
  map<GoodsID, Quantity> order;
  map<GoodsID, Quantity> all_orders;

  menu();
  cout << "\nSelect an action: ";
  cin >> command;

while(flag) {
  switch (command) {
    case 1:
      test->get_catalog();
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 2:
      cout << "Enter an ID and quantity of an item: ";
      cin >> item_id >> quantity;
      order.insert({item_id, quantity});
      all_orders.insert({item_id, quantity});
      test->make_order(order);
      cout << "\nSelect an action:";
      cin >> command;
      break;
    case 3:
      cout << "Enter an ID of the order: ";
      cin >> order_id;
      test->get_order_info(order_id);
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 4:
      test->get_order_list();
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 5:
      cout << "Enter an ID of the order: ";
      cin >> order_id;
      test->get_order(order_id);
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 6:
      cout << "Enter an ID of the order: ";
      cin >> order_id;
      test->collect_order(order_id);
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 7:
      cin.ignore();
      cout << "Enter title of new item: ";
      getline(cin, new_item);
      test->add_goods(new_item);
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 8:
      test->get_shortages();
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 9:
      test->get_reservations();
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 10:
      test->add_stock(all_orders);
      cout << "\nSelect an action: ";
      cin >> command;
      break;
    case 11:
      flag = false;
  }
}
  delete test;
  return 0;
}

void menu() {
  cout << setw(30) << "Menu\n";
  cout << setw(10) << "Order" << setw(35) << "Stock\n";
  cout << "1.Show catalog of goods." << setw(28) << "6.Collect an order.\n";
  cout << "2.Make an order." << setw(45) << "7.Add new item to the stock.\n";
  cout << "3.See an order." << setw(43) << "8.List of shortage items.\n";
  cout << "4.Get list of orders." << setw(37) << "9.List of reserved items.\n";
  cout << "5.Get yor order." << setw(47) << "10.Add request to buy new item.\n";
  cout << setw(40) << "11.Exit.\n";
}
