#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
class item
{
public:
	item();
	item(const char* itemName, unsigned int itemCode, float quantity, unsigned int price);

	std::string getItemName() { return name; }

	float getItemQuantity() { return quantity; }

	unsigned int getItemCode() { return code; }

	unsigned int getItemPrice() { return price; }

	void setItemName(const char* itemName) { name = itemName; }

	void setItemQuantity(float itemQuantity) { quantity = itemQuantity; }

	void setItemCode(unsigned int itemCode) { code = itemCode; }

	void setItemPrice(unsigned int itemPrice) { price = itemPrice; }

	void displayDetails();
protected:
	std::string name;
	float quantity;
	unsigned int code;
	unsigned int price;
};
#endif