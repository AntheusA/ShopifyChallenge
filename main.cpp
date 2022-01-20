#include <iostream>
#include "InventoryList.h"
using namespace std;

int main()
{
    InventoryList inventories = InventoryList();
    
    string input;
    while (input != "Exit" && input != "exit")
    {
        cout << "What would you like to do? \n Type 'Create' to add a new item \n Type 'Edit' to edit an existing item \n Type 'Delete' to delete an existing item \n Type 'View' to view a list of all items \n Type 'Location' to create a new inventory for a location \n Type 'Exit' to exit the inventory manager \n";
        cin >> input;
        
        
        if (input == "Create" || input == "create")
        {
            inventories.createItem(); 
        }
        if (input == "Location" || input == "location")
        {
            inventories.createInventory();
        }
        if (input == "Edit" || input == "edit")
        {
            inventories.editItem();
        }
        if (input == "Delete" || input == "delete")
        {
            inventories.removeItem();
        }
        if (input == "View" || input == "view")
        {
            inventories.viewInventory();
        }
    }
}
