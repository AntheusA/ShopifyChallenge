#include "Item.h"

Item::Item(string itemName, float itemPrice, int itemStock, Item* nextItem)
{
    name = itemName;
    price = itemPrice;
    stock = itemStock;
    next = nextItem;
}
