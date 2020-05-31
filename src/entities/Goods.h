#ifndef OOP_PROBLEMS_GOODS_H
#define OOP_PROBLEMS_GOODS_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned int GoodsID; // creating separate type for goods IDs

typedef unsigned int Quantity; // creating separate type for goods quantity

class Goods {
private:
  GoodsID _id; // variable for an uniq ID of good
  string _title; // variable for an uniq title of good
public:
  Goods(GoodsID id, string title); // constructor for Good class

  GoodsID get_id(); // method for getting good ID

  string get_title(); // method for getting good title
};

#endif //OOP_PROBLEMS_GOODS_H
