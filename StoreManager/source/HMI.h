#ifndef HMI_H
#define HMI_H

#include "AccessConfig.h"
#include "ItemManager.h"
#include "Billing.h"
#include <vector>

class hmi
{
public:
	hmi();

	itemManager* getItemManager() {return _iManager; }

	void mainMenu();

	void addNewItem();

	void billing();

	void removeItem();

	void searchItemPrice();

	void searchItemCode();

	void displayAllItems();

	void newBillItem();

	void deleteBillItem();

protected:
	itemManager* _iManager;
	readConfig* _configReader;
	writeConfig* _configwriter;
	bill* _customerBill;
};
#endif