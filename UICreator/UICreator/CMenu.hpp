#pragma once

#include <functional>
#include <string>
#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	CMenu(const std::string&  inMenuName, const std::string& inCommandName, CMenuItem* inParent);

	virtual ~CMenu() = default;

	bool run() final override;
	bool runPredefinedCommands(const std::vector<std::vector<std::string>>& inCommands) final override;

private:
	CMenuItem* runImpl(const std::vector<std::string>& userInput);

	bool isAction(const std::string& userInputArgumentOnPosition0);
	CMenuItem* interpretAction(const std::vector<std::string>& userInput);
	CMenuItem* interpretCommand(CMenuItem* itemWithMatchedByNameCommand);
	bool isAfterReceivedFirstCommand;

	CMenuItem* cursor; // only to be used by RUNNERS
};
