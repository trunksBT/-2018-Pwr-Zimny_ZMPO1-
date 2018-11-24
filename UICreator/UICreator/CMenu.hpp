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
	std::vector<std::string> receiveAndLexUserInput();
	bool validateUserInput(const std::vector<std::string>& inCommand, int numberOfExpectedArgs);

	bool isAction(const std::string& userInputArgumentOnPosition0);
	void interpretAction(const std::vector<std::string>& userInput);

	bool isCommand(const std::string& zeroArgOfUserInput);
	void interpretCommand(const std::vector<std::string>& userInput);
};
