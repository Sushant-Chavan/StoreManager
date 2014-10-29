#ifndef HMI_H
#define HMI_H

#include "ReadConfig.h"
#include "ItemManager.h"
#include "Billing.h"
#include <vector>

class hmi
{
public:
	hmi();

	itemManager* getItemManager() {return iManager; }

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

	void addDefaultItems();

	itemManager* iManager;
	readConfig* configReader;
	bill* customerBill;
};
#endif