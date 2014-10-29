#include "HMI.h"
using namespace std;

hmi::hmi()
{
	iManager = new itemManager;
	//configReader = new readConfig(iManager);
	customerBill = NULL;
	addDefaultItems();
}

void hmi::addDefaultItems()
{
	iManager->addItem("Rice", 1, 1000, 10);
	iManager->addItem("Wheat", 2, 1000, 20);
	iManager->addItem("Jowar", 3, 1000, 15);
	iManager->addItem("Atta", 4, 1000, 40);
	iManager->addItem("Maida", 5, 1000, 30);
}

void hmi::mainMenu()
{
	cout << "Choose an option : " << endl;

	cout << "1. Create a bill." << endl;
	cout << "2. Search for Item Price" << endl;
	cout << "3. Search for Item Code" << endl;
	cout << "4. Display All items in inventory" << endl;
	cout << "5. Add new item to inventory." << endl;
	cout << "6. Remove an item from inventory." << endl;

	unsigned int choice = 0;

	cin >> choice;

	switch(choice)
	{
	case 1: billing();
		break;
	case 2: searchItemPrice();
		break;
	case 3: searchItemCode();
		break;
	case 4: displayAllItems();
		break;
	case 5: addNewItem();
		break;
	case 6: removeItem();
		break;
	default: cout << "Invalid Choice!" << std::endl << endl;
		mainMenu();
		break;
	}
}

void hmi::billing()
{
	// TODO: Clear Screen
	if(customerBill == NULL)
	{
		customerBill = new bill;
	}

	cout << "Choose an option for Billing: " << endl;

	cout << "1. Add Item." << endl;
	cout << "2. Remove Item" << endl;
	cout << "3. Display Bill" << endl;
	cout << "4. Compute bill" << endl;
	cout << "5. Main Menu" << endl;

	unsigned int choice = 0;

	cin >> choice;

	switch(choice)
	{
	case 1: newBillItem();
		break;
	case 2: deleteBillItem();
		break;
	case 3: customerBill->displayDetails();
		billing();
		break;
	case 4: customerBill->compute();
		billing();
		break;
	case 5: delete customerBill;
		customerBill = NULL;
		mainMenu();
		break;
	default: cout << "Invalid Choice!" << std::endl << endl;
		billing();
		break;
	}
}

void hmi::newBillItem()
{
	unsigned int itemCode, quantity;

	cout << "Enter the item Code of Item to be added to bill: ";
	cin >> itemCode;

	if(iManager->itemPresent(itemCode))
	{
		cout << endl << "Enter Quantity of the item: ";
		cin >> quantity;

		item billItem = iManager->getItem(itemCode);
		
		customerBill->addItem(billItem, quantity);
	}
	else
	{
		cout << "Item Not present in inventory!" << endl;
	}

	billing();
}

void hmi::deleteBillItem()
{
	unsigned int itemCode;

	cout << "Enter the item Code of Item to be removed from the bill: ";
	cin >> itemCode;

	customerBill->removeItem(itemCode);

	billing();
}

void hmi::addNewItem()
{
	std::string itemName;
	unsigned int price, itemCode;
	float quantity;

	cout << "Adding a new item to inventory..." << endl;
	cout << "Enter the Item Name: ";	
	cin >> itemName;

	cout << endl << "Enter Item Code: ";
	cin >> itemCode;

	cout << endl << "Enter the pre unit price: ";
	cin >> price;

	cout << endl << "Enter the quantity: ";
	cin >> quantity;

	iManager->addItem(itemName.c_str(), itemCode, quantity, price);
	mainMenu();
}

void hmi::removeItem()
{
	unsigned int itemCode;
	cout << "Enter the Item Code of item to be removed: ";
	cin >> itemCode;

	iManager->removeItem(itemCode);

	mainMenu();
}

void hmi::searchItemPrice()
{
	mainMenu();
}

void hmi::searchItemCode()
{
	mainMenu();
}

void hmi::displayAllItems()
{
	iManager->displayAllItemDetails();

	mainMenu();
}