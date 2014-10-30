#include "Item.h"
using namespace std;

item::item()
{
	_name = "Invalid";
	_quantity = -1.0f;
	_code = 0;
}

item::item(const char* itemName, unsigned int itemCode, float quantity, float price)
{
	setItemName(itemName);
	setItemCode(itemCode);
	setItemQuantity(quantity);
	setItemPrice(price);
}

void item::displayDetails()
{
	cout << "Item Name: " << getItemName().c_str();

	cout << ", Item Code: " << getItemCode();

	cout << ", Item Quantity: " << getItemQuantity();

	cout << ", Item Price: " << getItemPrice() << endl;
}