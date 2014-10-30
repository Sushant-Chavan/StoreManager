#ifndef ACCESS_CONFIG_H
#define ACCESS_CONFIG_H

#include "ItemManager.h"

class readConfig
{
public:
	readConfig();
	readConfig(itemManager* iManager);

	bool readItemData();

protected:
	itemManager* _itemManager;
};

class writeConfig
{
public:
	writeConfig();
	writeConfig(itemManager* iManager);

	bool writeItemData();

protected:
	itemManager* _itemManager;
};
#endif