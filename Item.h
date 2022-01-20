#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <string>
using namespace std;
class Item {


public:
    string name;
    float price;
    int stock;
    Item* next;


    Item(string itemName, float itemPrice, int itemStock, Item* nextItem);
};



#endif
