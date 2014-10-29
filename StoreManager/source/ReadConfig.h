#ifndef READ_CONFIG_H
#define READ_CONFIG_H

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
#endif