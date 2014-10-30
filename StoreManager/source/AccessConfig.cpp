#include "AccessConfig.h"
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

	infile.close();
	return true;
}

writeConfig::writeConfig()
{
	_itemManager = NULL;
}

writeConfig::writeConfig(itemManager* iManager)
{
	_itemManager = iManager;
}

bool writeConfig::writeItemData()
{
	bool retval = true;
	char filestream[BUFF_SIZE];
	stringstream ss;
	char check;

	ifstream infile("F:\\Projects\\StoreManager\\Debug\\Config\\Config.txt");
	if (!infile.good())
	{
		char error[250];
		cout << "File Config.txt could not be openedfor reading!\n"; // Report error
		cout << "Error code: " << strerror_s(error, errno); // Get some info as to why
		retval = false;
	}

	ofstream tempFile("F:\\Projects\\StoreManager\\Debug\\Config\\Temp.txt");
	if (!tempFile.good())
	{
		char error[250];
		cout << "File Temp.txt could not be created!\n"; // Report error
		cout << "Error code: " << strerror_s(error, errno); // Get some info as to why
		retval = false;
	}

	do
	{
		infile.getline(filestream, BUFF_SIZE);
		tempFile << filestream;
		tempFile << "\n";
		check = filestream[0];
	} while (check != '<');

	infile.close();
	tempFile.close();

	infile.open("F:\\Projects\\StoreManager\\Debug\\Config\\Temp.txt");
	if (!infile.good())
	{
		char error[250];
		cout << "File Temp.txt could not be opened for reading!\n"; // Report error
		cout << "Error code: " << strerror_s(error, errno); // Get some info as to why
		retval = false;
	}

	ofstream outFile("F:\\Projects\\StoreManager\\Debug\\Config\\Config.txt");
	if (!outFile.good())
	{
		char error[250];
		cout << "File Config.txt could not be opened for writing!\n"; // Report error
		cout << "Error code: " << strerror_s(error, errno); // Get some info as to why
		retval = false;
	}

	outFile.clear();
	
	do
	{
		infile.getline(filestream, BUFF_SIZE);
		outFile << filestream;
		outFile << "\n";
		check = filestream[0];
	} while (check != '<');

	infile.close();
	if (remove("F:\\Projects\\StoreManager\\Debug\\Config\\Temp.txt") != 0)
		cout << "Error deleting Temp.txt!!";

	for (unsigned int i = 0; i < _itemManager->getNumberOfItems(); i++)
	{
		item myItem = _itemManager->getMappedItem(i);
		string itemName = myItem.getItemName();

		char itemCode[10];
		sprintf_s(itemCode, " %d ", myItem.getItemCode());

		char itemQuantity[10];
		
		float quantity = myItem.getItemQuantity();
		int d1 = quantity;            // Get the integer part (678).
		float f2 = quantity - d1;     // Get fractional part (678.0123 - 678 = 0.0123).
		int d2 = trunc(f2 * 100);   // Turn into integer (123).
		sprintf_s(itemQuantity, " %d.%d ", d1, d2);

		char itemPrice[10];
		sprintf_s(itemPrice, " %d ", myItem.getItemPrice());

		char outString[250];

		strcpy_s(outString, itemName.c_str());
		strcat_s(outString, itemCode);
		strcat_s(outString, itemQuantity);
		strcat_s(outString, itemPrice);

		outFile << outString;
		outFile << "\n";
	}

	outFile << "<\\Start>";
	outFile.close();
	return retval;

}