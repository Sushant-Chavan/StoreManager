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

	ifstream infile;
	infile.open("Config.txt", std::ifstream::in);

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

	//Extract Item Name
	string tempItemName = filestream;
	string itemName;
	itemName.reserve(tempItemName.size() - 2);
	for (int i = 1; i < itemName.size() - 1; i++)
	{
		itemName[i - 1] = tempItemName[i];
	}
	int i = 0;
}