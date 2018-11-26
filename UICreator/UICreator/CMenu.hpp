#pragma once

#include <vector>
#include "CMenuItem.hpp"

class CMenu : public CMenuItem
{
public:
	CMenu(const std::string& inMenuName, const std::string& inCommandName);
	virtual ~CMenu() = default;

	void run();
private:
	std::vector<std::string> performLexer(std::string inCommand);
	std::vector<std::string> receiveAndLexUserInput();
	bool validateUserInput(const std::vector<std::string>& inCommand, int numberOfExpectedArgs);

	bool isAction(const std::string& userInputArgumentOnPosition0);
	void interpretAction(const std::vector<std::string>& userInput);
};
