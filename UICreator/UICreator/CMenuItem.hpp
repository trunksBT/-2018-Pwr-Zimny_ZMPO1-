#pragma once

#include <string>
#include <vector>
#include "Utils.hpp"

class CMenuItem
{
public:
	CMenuItem(
		std::string inMenuName = defaultVals::DEFAULT_STRING_VAL,
		std::string inCommandName = defaultVals::DEFAULT_STRING_VAL);
	~CMenuItem();

	virtual void run() = 0;
	std::string getMenuName();
	std::string getCommandName();

protected:
	void addObject(CMenuItem* inObj);
	CMenuItem* findMenu(std::string menuName);

	std::vector<CMenuItem*> children;
	CMenuItem* parent = NULL;
	std::string toString();
	std::string toStringFlatTree();
	std::string toStringTree(int indent = 0);
	std::string insertIndent(int multiplier);

private:
	std::string s_name;
	std::string s_command;
};
