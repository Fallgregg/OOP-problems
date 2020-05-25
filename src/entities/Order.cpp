#include "Order.h"

Order::Order(OrderID id, map<GoodsID, Quantity> list) {
  _id = id;
  _status = Status::PROCESSING;
  _list = list;
}

Order::Order(OrderID id, map<GoodsID, Quantity> list, Status status) {
  _id = id;
  _status = status;
  _list = list;
}

OrderID Order::get_id() {
  return _id;
}

Status Order::get_status() {
  return _status;
}

Status Order::set_status(Status status) {
  return _status = status;
}

map<GoodsID, Quantity> Order::get_list() {
  return _list;
}
