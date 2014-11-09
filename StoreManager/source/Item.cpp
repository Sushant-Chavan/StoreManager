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

void item::displayName()
{
	cout << "Item Name: " << getItemName().c_str();
}

void item::displayPrice()
{
	cout << "Item Price: " << getItemPrice();
}

void item::displayCode()
{
	cout << "Item Code: " << getItemCode();
}

void item::displayQuantity()
{
	cout << "Item Quantity: " << getItemQuantity();
}