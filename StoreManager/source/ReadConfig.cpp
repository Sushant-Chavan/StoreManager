#include "ReadConfig.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define BUFF_SIZE 250
readConfig::readConfig()
{
	_itemManager = NULL;
}

readConfig::readConfig(itemManager* iManager)
{
	_itemManager = iManager;
}

bool readConfig::readItemData()
{
	char filestream[BUFF_SIZE];

	ifstream infile("F:\\Projects\\StoreManager\\Debug\\Config\\Config.txt");

	if (!infile.good())
	{
		char error[250];
		cout << "File could not be opened!\n"; // Report error
		cout << "Error code: " << strerror_s(error, errno); // Get some info as to why
		return false;
	}

	stringstream ss;
	char check;

	// eliminate all comment lines begining with '/'
	do
	{
		infile.getline(filestream, BUFF_SIZE);
		check = filestream[0];
	} while (check != '<');

	infile.getline(filestream, BUFF_SIZE);
	while (filestream[0] != '<')
	{
		//Extract Item Details
		string itemName;
		unsigned int itemCode;
		float itemQuantity;
		unsigned int itemPrice;

		ss << filestream;
		ss >> itemName;
		ss >> itemCode;
		ss >> itemQuantity;
		ss >> itemPrice;

		_itemManager->addItem(itemName.c_str(), itemCode, itemQuantity, itemPrice);

		ss << "";
		ss.clear();
		infile.getline(filestream, BUFF_SIZE);
	}
	return true;
}