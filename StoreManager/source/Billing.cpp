#include "Billing.h"

void bill::billedItem::display()
{
	std::cout << myItem.getItemName() << ", " << myItem.getItemQuantity() << "gms, Rs." << myItem.getItemPrice() << " per unit." << "----> " << quantity << " units" << std::endl;
}

float bill::billedItem::computePrice()
{
	return (myItem.getItemPrice() * quantity);
}

void bill::addItem(item& newItem, unsigned int quantity)
{
	std::map<unsigned int, billedItem>::iterator itr;
	itr = _itemList.find(newItem.getItemCode());

	// If item already not present in the bill add item
	if(itr == _itemList.end())
	{
		billedItem i;
		i.myItem = newItem;
		i.quantity = quantity;

		_itemList.insert( std::pair<unsigned int, billedItem>(newItem.getItemCode(), i) );
	}
	else // If item already present in bill, update the quantity
	{
		itr->second.quantity = quantity;
	}
}

void bill::removeItem(unsigned int itemCode)
{
	std::map<unsigned int, billedItem>::iterator itr;
	itr = _itemList.find(itemCode);

	if(itr != _itemList.end())
	{
		_itemList.erase(itr);
	}
	else
	{
		std::cout << "Item Not Present In The Bill!!" << std::endl;
	}
}

void bill::displayDetails()
{
	std::cout << std::endl <<  "**********Bill Details**********" << std::endl << std::endl;
	std::map<unsigned int, billedItem>::iterator itr;
	for(itr = _itemList.begin(); itr != _itemList.end(); itr++)
	{
		itr->second.display();
	}
	std::cout << std::endl;
	compute();
	std::cout << "******************************" << std::endl;
}

float bill::compute()
{
	float totalAmount = 0;
	std::map<unsigned int, billedItem>::iterator itr;

	for(itr = _itemList.begin(); itr != _itemList.end(); itr++)
	{
		totalAmount += itr->second.computePrice();
	}

	std::cout << "Current Bill Amount = " << totalAmount << std::endl;

	return totalAmount;
}