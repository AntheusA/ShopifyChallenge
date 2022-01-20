#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <string>

class Inventory {
	public:
		int size;
		Item* itemHead;
		Inventory* next;
		string name;

		Inventory(string inventoryName, Inventory* nextInventory);
};


#endif
