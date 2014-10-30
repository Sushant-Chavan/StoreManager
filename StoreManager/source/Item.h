#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include<map>
class item
{
public:
	item();
	item(const char* itemName, unsigned int itemCode, float quantity, float price);

	std::string getItemName() { return _name; }

	float getItemQuantity() { return _quantity; }

	unsigned int getItemCode() { return _code; }

	float getItemPrice() { return _price; }

	void setItemName(const char* itemName) { _name = itemName; }

	void setItemQuantity(float itemQuantity) { _quantity = itemQuantity; }

	void setItemCode(unsigned int itemCode) { _code = itemCode; }

	void setItemPrice(float itemPrice) { _price = itemPrice; }

	void setItemMrp(float quantity, float price);

	void displayDetails();
protected:
	std::string _name;
	unsigned int _code;

	float _quantity;
	float _price;
};
#endif