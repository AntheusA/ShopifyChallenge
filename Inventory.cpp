#include "Inventory.h"
#include <iostream>

Inventory::Inventory(string inventoryName, Inventory* nextInventory)
{
	size = 0;
	itemHead = NULL;
	name = inventoryName;
	next = nextInventory;
}
