#pragma once

#include <string>
#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	CMenu(const std::string& inMenuName, const std::string& inCommandName);
	virtual ~CMenu() = default;

	void run();

private:

	bool isAction(const std::string& userInputArgumentOnPosition0);
	void interpretAction(const std::vector<std::string>& userInput);
};
