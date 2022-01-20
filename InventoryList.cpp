#include "InventoryList.h"
#include <iostream>

InventoryList::InventoryList()
{
	size = 0;
	head = NULL;
}

void InventoryList::createInventory()
{
    Inventory* nextInventory = head;
    
    string inputName;
    
    cout << "Enter the name of the location: ";
    cin >> inputName;
    
    if (nextInventory == NULL)
	{
        Inventory* newInventory = new Inventory(inputName, NULL);
		head = newInventory;
		size++;
        return;
	}
	
	if (nextInventory != NULL)
	{
        Inventory* newInventory = new Inventory(inputName, nextInventory);
		head = newInventory;
		size++;
        return;
	}
}

void InventoryList::createItem()
{
    string inputLocation;
    Inventory* nextInventory = head;
    string inputName;
    float inputPrice;
    int inputStock;
    
    cout << "What location would you like to add the item to: ";
    cin >> inputLocation;
    
    while (nextInventory != NULL)
    {
        
        if (nextInventory->name == inputLocation)
        {
            cout << "Enter the name of the item: ";
            cin >> inputName;
            cout << "Enter the price of the item: ";
            cin >> inputPrice;
            cout << "Enter the stock of the item: ";
            cin >> inputStock;
            
            if (nextInventory->itemHead == NULL)
            {
                Item* newItem = new Item(inputName, inputPrice, inputStock, NULL);
                nextInventory->itemHead = newItem;
                nextInventory->size++;
                return;
            }
            else if (nextInventory->itemHead != NULL)
            {
                Item* newItem = new Item(inputName, inputPrice, inputStock, nextInventory->itemHead);
                nextInventory->itemHead = newItem;
                nextInventory->size++;
                return;
            }
        }
        
        nextInventory = nextInventory->next;
    }
}

void InventoryList::editItem()
{
    string inputInventory;
    string inputItem;
    string inputEdit;
    string editName;
    double editPrice;
    int editStock;
    
	Inventory* nextInventory = head;
    Item* nextItem = nextInventory->itemHead;
	
	cout << "Which inventory would you like to edit an item in: ";
	cin >> inputInventory;
	
	
	while (nextInventory != NULL)
    {
        if (inputInventory == nextInventory->name)
        {
            cout << "Which item would you like to edit: ";
	        cin >> inputItem;

            while (nextItem != NULL)
            {
                if (nextItem->name == inputItem)
                {
                    cout << "What would you like to edit (Name, Price, Stock): ";
	                cin >> inputEdit;
	                
	                if (inputEdit == "Name")
	                {
	                    cout << "What is the new name: ";
	                    cin >> editName;
	                    
	                    nextItem->name = editName;
	                    
	                    return;
	                }
	                else if (inputEdit == "Price")
	                {
	                    cout << "What is the new price: ";
	                    cin >> editPrice;
	                    
	                    nextItem->price = editPrice;
	                    
	                    return;
	                }
	                else if (inputEdit == "Stock")
	                {
	                    cout << "What is the new stock: ";
	                    cin >> editStock;
	                    
	                    nextItem->stock = editStock;
	                    
	                    return;
	                }
                }
                
                nextItem = nextItem->next;
            }
        }
        
        nextInventory = nextInventory->next;
        nextItem = nextInventory->itemHead;
    }
}

void InventoryList::removeItem()
{
    string inputInventory;
    string inputItem;
	Inventory* nextInventory = head;
    Item* nextItem = nextInventory->itemHead;
	
	cout << "Which inventory would you like to remove an item from: ";
	cin >> inputInventory;
	
	
	while (nextInventory != NULL)
    {
        if (inputInventory == nextInventory->name)
        {
            cout << "Which item would you like to remove: ";
	        cin >> inputItem;
            
            if (nextItem->name == inputItem)
            {
        		nextInventory->itemHead = nextItem->next;
        		nextItem = NULL;
        		size--;
        		return;
            }
            
            while (nextItem != NULL)
            {
                if (nextItem->name == inputItem)
                {
                    Item* deletePtr = nextItem->next;
        			nextItem->next = nextItem->next->next;
        			delete deletePtr;
        			size--;
        			return;
                }
                
                nextItem = nextItem->next;
            }
        }
        
        nextInventory = nextInventory->next;
        nextItem = nextInventory->itemHead;
    }
}

void InventoryList::viewInventory()
{
    Inventory* nextInventory = head;
    Item* nextItem = nextInventory->itemHead;
    
    while (nextInventory != NULL)
    {
        cout << " Inventory: " << nextInventory->name << " \n ================== \n ";
        
        while (nextItem != NULL)
        {
            cout << "Name: " << nextItem->name << "\t Price: " << nextItem->price << "\t Stock: " << nextItem->stock << "\n";
            
            nextItem = nextItem->next;
        }
        
        cout << "\n\n";
        
        nextInventory = nextInventory->next;
        nextItem = nextInventory->itemHead;
    }
}
