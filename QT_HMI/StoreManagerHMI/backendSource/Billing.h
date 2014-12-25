#ifndef BILLING_H
#define BILLING_H

#include <map>
#include "Item.h"

class bill
{
public:
	struct billedItem
	{
		item myItem;
		unsigned int quantity;

		void display();

		float computePrice();
	};

	void displayDetails();
	float compute();
	void removeItem(unsigned int itemCode);
	void addItem(item& newItem, unsigned int quantity);
protected:
	std::map<unsigned int, billedItem> _itemList;
};

#endif
