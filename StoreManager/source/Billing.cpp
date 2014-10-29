#include "Billing.h"

void bill::billedItem::display()
{
	std::cout << myItem.getItemName() << ", " << myItem.getItemQuantity() << "gms, Rs." << myItem.getItemPrice() << " per unit." << "----> " << quantity << " units" << std::endl;
}

unsigned int bill::billedItem::computePrice()
{
	return (myItem.getItemPrice() * quantity);
}

void bill::addItem(item& newItem, unsigned int quantity)
{
	std::map<unsigned int, billedItem>::iterator itr;
	itr = itemList.find(newItem.getItemCode());

	// If item already not present in the bill add item
	if(itr == itemList.end())
	{
		billedItem i;
		i.myItem = newItem;
		i.quantity = quantity;

		itemList.insert( std::pair<unsigned int, billedItem>(newItem.getItemCode(), i) );
	}
	else // If item already present in bill, update the quantity
	{
		itr->second.quantity = quantity;
	}
}

void bill::removeItem(unsigned int itemCode)
{
	std::map<unsigned int, billedItem>::iterator itr;
	itr = itemList.find(itemCode);

	if(itr != itemList.end())
	{
		itemList.erase(itr);
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
	for(itr = itemList.begin(); itr != itemList.end(); itr++)
	{
		itr->second.display();
	}
	std::cout << std::endl;
	compute();
	std::cout << "******************************" << std::endl;
}

unsigned int bill::compute()
{
	unsigned int totalAmount = 0;
	std::map<unsigned int, billedItem>::iterator itr;

	for(itr = itemList.begin(); itr != itemList.end(); itr++)
	{
		totalAmount += itr->second.computePrice();
	}

	std::cout << "Current Bill Amount = " << totalAmount << std::endl;

	return totalAmount;
}