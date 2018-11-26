#pragma once

#include <string>
#include <vector>
#include "Utils.hpp"

class CMenuItem
{
public:
	CMenuItem(std::string inMenuName, std::string inCommandName);
	virtual ~CMenuItem();

	virtual void run() = 0;

protected:
	std::string getName();
	std::string getCommandName();

	CMenuItem* findName(const std::string& objectName);
	CMenuItem* findCommand(const std::string& commandName);

	bool deleteChildren(const std::string& objectName);

	std::string toString();
	std::string toStringFlatTree();
	std::string toStringTree(int indent = 0);
	std::string insertIndent(int multiplier);

	std::vector<CMenuItem*> children;

private:
	std::string s_name;
	std::string s_command;
};
