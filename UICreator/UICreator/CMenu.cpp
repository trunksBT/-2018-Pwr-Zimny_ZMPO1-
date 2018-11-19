#include "pch.h"
#include <iostream>
#include <boost/tokenizer.hpp>

#include "CMenu.hpp"

using namespace defaultVals;
using namespace baseCommands;

CMenu::CMenu(std::string inMenuName, std::string inCommandName)
	: CMenuItem(inMenuName, inCommandName)
{
}


CMenu::~CMenu()
{
}

void CMenu::run()
{
	std::string commandHeader;
	std::string menuName;
	std::string commandName;
	//std::cout << CMenuItem::getMenuName() << SEPARATOR << CMenuItem::getCommandName();
	do
	{
		std::vector<std::string> command = receiveAndLexCommandFromUser();
		if (command.size() == 0)
			return;
		
		commandHeader = command[0];

		if (commandHeader == CREATE_MENU)
		{
			menuName = command[1];
			CMenuItem* searchedElementInMenu = findMenu(command[1]);
			if (NULL == searchedElementInMenu)
			{
				addObject(new CMenu(menuName, commandName));
				system("cls");
			}
			else
			{
				system("cls");
				std::cout << "There is such menu callable via " << menuName << '\n';
			}
			std::cout << toStringFlatTree() << "\n";
		}
		else if (commandHeader == SELECT)
		{
			menuName = command[1];
			CMenuItem* searchedElementInMenu = findMenu(command[1]);
			if (NULL != searchedElementInMenu)
			{
				system("cls");
				searchedElementInMenu->run();
			}
			else
			{
				system("cls");
				std::cout << "There is no menu callable via " << menuName << '\n';
			}
			std::cout << toStringFlatTree() << "\n";
		}
		else if (commandHeader == PRINT)
		{
			std::cout << toStringTree() << "\n";
		}
		else if (commandHeader == HELP)
		{
			std::cout << "Create MENU_NAME CMD_NAME - To create MENU_NAME callable via CMD_NAME" << "\n";
			std::cout << "Select CMD_NAME - To select MENU via CMD_NAME" << "\n";
			std::cout << "Print - To print all menu with submenus" << "\n";
			std::cout << "Back - To back to previous menu/ close app" << "\n";
		}
		else
		{
			system("cls");
			std::cout << commandHeader << " is unknown command" << "\n";
			std::cout << toStringFlatTree() << "\n";
		}
	} while (commandHeader != BACK);
}

std::vector<std::string> CMenu::performLexer(std::string inCommand)
{
	boost::char_separator<char> sep(SEPARATOR);
	boost::tokenizer<boost::char_separator<char>> tokens (inCommand, sep);
	std::vector<std::string> retVal(tokens.begin(), tokens.end());
	return retVal;
} // wziales z neta aby zabezpieczyc sie przed blednymi wejsciami uzytkownika

std::vector<std::string> CMenu::receiveAndLexCommandFromUser()
{
	std::string inChain;
	do
	{
		std::cout << CURSOR_SIGN;
		getline(std::cin, inChain);
	} while (inChain.size() == ZERO);
	return performLexer(inChain);
}