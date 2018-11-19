#pragma once

#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	CMenu(std::string inMenuName, std::string inCommandName);

	virtual ~CMenu();

	void run();

private:
	std::vector<std::string> performLexer(std::string inCommand);
	std::vector<std::string> receiveAndLexCommandFromUser();
};
