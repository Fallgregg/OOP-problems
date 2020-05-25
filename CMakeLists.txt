cmake_minimum_required(VERSION 3.16)
project(OOP_problems)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_problems main.cpp src/entities/Goods.cpp src/entities/Goods.h src/catalog/Catalog.cpp src/catalog/Catalog.h src/warehouse/Warehouse.cpp src/warehouse/Warehouse.h)