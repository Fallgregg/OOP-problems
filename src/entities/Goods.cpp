#include "Goods.h"

Goods::Goods(std::string title) {
  _title = title;
}

std::string Goods::get_title() {
  return _title;
}
