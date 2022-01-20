#ifndef INVENTORYLIST_H
#define INVENTORYLIST_H

#include "Inventory.h"
#include <string>

class InventoryList {
	private:
		int size;
		Inventory* head;

	public:
		InventoryList();
		void createInventory();
		void createItem();
		void editItem();
		void removeItem();
		void viewInventory();
};


#endif
