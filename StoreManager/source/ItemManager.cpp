#include "ItemManager.h"

itemManager::itemManager()
{
	_itemMap = new std::map<unsigned int, item*>;
}

void itemManager::addItem(const char* itemName, unsigned int itemCode, float quantity, float price)
{
	item* newItem = new item;
	newItem->setItemName(itemName);
	newItem->setItemCode(itemCode);
	newItem->setItemQuantity(quantity);
	newItem->setItemPrice(price);

	_itemMap->insert( std::pair<unsigned int, item*>(itemCode, newItem) );
}

void itemManager::addItem(item& Item)
{
	item* newItem = new item;

	newItem->setItemName(Item.getItemName().c_str());
	newItem->setItemCode(Item.getItemCode());
	newItem->setItemQuantity(Item.getItemQuantity());
	newItem->setItemPrice(Item.getItemPrice());

	_itemMap->insert( std::pair<unsigned int, item*>(Item.getItemCode(), newItem) );
}

void itemManager::removeItem(unsigned int itemCode)
{
	std::map<unsigned int, item*>::iterator itr;
	itr = _itemMap->find(itemCode);

	if(itr != _itemMap->end())
	{
		_itemMap->erase(itr);
		std::cout << "Item with code " << itemCode << " erased!" << std::endl;
	}
	else
	{
		std::cout << "Item with code " << itemCode << " not found!" << std::endl;
	}
}

item itemManager::getItem(unsigned int itemCode)
{
	std::map<unsigned int, item*>::iterator itr;
	itr = _itemMap->find(itemCode);

	item newItem;

	if(itr != _itemMap->end())
	{
		newItem = *(itr->second);
	}
	return newItem;
}

item itemManager::getMappedItem(unsigned int positionInMap)
{
	std::map<unsigned int, item*>::iterator itr = _itemMap->begin();
	for (unsigned int i = 0; i < positionInMap; i++)
	{
		itr++;
	}

	item newItem;

	if (itr != _itemMap->end())
	{
		newItem = *(itr->second);
	}
	return newItem;
}

void itemManager::displayAllItemCodes()
{
	std::map<unsigned int, item*>::iterator itr;

	std::cout << "Item codes of Items currently present with the item Manager : " << std::endl;
	for(itr = _itemMap->begin(); itr != _itemMap->end(); itr++)
	{
		std::cout << itr->second->getItemCode() << std::endl;
	}
}

void itemManager::displayAllItemNames()
{
	std::map<unsigned int, item*>::iterator itr;

	std::cout << "Item Names of Items currently present with the item Manager : " << std::endl;
	for(itr = _itemMap->begin(); itr != _itemMap->end(); itr++)
	{
		std::cout << itr->second->getItemName() << std::endl;
	}
}

void itemManager::displayAllItemDetails()
{
	std::map<unsigned int, item*>::iterator itr;

	std::cout << "Details of Items currently present with the item Manager : " << std::endl;
	for(itr = _itemMap->begin(); itr != _itemMap->end(); itr++)
	{
		itr->second->displayDetails();
		std::cout << std::endl;
	}
}

bool itemManager::itemPresent(unsigned int itemCode)
{
	bool retval = false;

	std::map<unsigned int, item*>::iterator itr;
	itr = _itemMap->find(itemCode);

	if(itr != _itemMap->end())
	{
		retval = true;
	}
	return retval;
}