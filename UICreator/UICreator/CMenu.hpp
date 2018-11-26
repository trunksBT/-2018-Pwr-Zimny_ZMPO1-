#pragma once

#include <functional>
#include <string>
#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	CMenu(const std::string& inMenuName, const std::string& inCommandName);
	virtual ~CMenu() = default;

	void run() final override;
	void runPredefinedCommands(const std::vector<std::vector<std::string>>& inCommands);

private:
	bool runImpl(const std::vector<std::string>& userInput);

	bool isAction(const std::string& userInputArgumentOnPosition0);
	void interpretAction(const std::vector<std::string>& userInput);
};
