#pragma once

#include <functional>
#include <string>
#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	//CMenu(const std::string& inMenuName, const std::string& inCommandName);
	CMenu(const std::string&  inMenuName, const std::string& inCommandName, CMenuItem* inParent);

	virtual ~CMenu() = default;

	bool run() final override;
	bool runPredefinedCommands(const std::vector<std::vector<std::string>>& inCommands) final override;

private:
	bool runImpl(const std::vector<std::string>& userInput);

	bool isAction(const std::string& userInputArgumentOnPosition0);
	void interpretAction(const std::vector<std::string>& userInput);

	CMenu* cursor;
};
