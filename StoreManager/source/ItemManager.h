#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include "Item.h"
#include <map>
class itemManager
{
public:
	itemManager();

	void addItem(const char* itemName, unsigned int itemCode, float quantity, unsigned int price);

	unsigned int getNumberOfItems(){ return itemMap->size(); }

	void addItem(item& newItem);

	void removeItem(unsigned int itemCode);

	item getItem(unsigned int itemCode);

	item getMappedItem(unsigned int positionInMap);

	void displayAllItemCodes();

	void displayAllItemNames();

	void displayAllItemDetails();

	bool itemPresent(unsigned int itemCode);

protected:
	std::map<unsigned int, item*>* itemMap;
};

#endif