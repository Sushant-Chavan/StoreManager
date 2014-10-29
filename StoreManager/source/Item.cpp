#include "Item.h"
using namespace std;

item::item()
{
	name = "Invalid";
	quantity = -1.0f;
	code = 0;
	price = 0;
}

item::item(const char* itemName, unsigned int itemCode, float quantity, unsigned int price)
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