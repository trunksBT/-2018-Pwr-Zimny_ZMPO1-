#include "pch.h"
#include <iostream>
#include <boost/tokenizer.hpp>

#include "CMenu.hpp"
#include "CMenuCommand.hpp"

using namespace defaultVals;
using namespace actions;

CMenu::CMenu(const std::string& inMenuName, const std::string& inuserInputName)
	: CMenuItem(inMenuName, inuserInputName)
{}

void CMenu::run()
{
	std::string zeroArgOfUserInput;
	do
	{
		std::vector<std::string> userInput = receiveAndLexUserInput();
		// userInput[0] - firstArg userAction
		// userInput[1] / userInput[2] depends from userAction, please check the if else
		if (userInput.size() == 0)
		{
			return;
		}
		zeroArgOfUserInput = userInput[idx::COMMAND_OR_ACTION_NAME];

		if (isAction(zeroArgOfUserInput))
		{
			interpretAction(userInput);
		}
		else if (CMenuItem* command = findCommand(zeroArgOfUserInput))
		{
			command->run();
			std::cout << toStringFlatTree() << END_LINE;
		}
		else if (zeroArgOfUserInput == BACK)
		{
			system("cls");
		}
		else
		{
			system("cls");
			std::cout << zeroArgOfUserInput << ": nie ma takiej pozycji" << END_LINE << END_LINE;
			funs::actionHelp();
		}
	} while (zeroArgOfUserInput != BACK);
}

std::vector<std::string> CMenu::performLexer(std::string inuserInput)
{
	boost::char_separator<char> sep(SPACE_AS_SEPARATOR);
	boost::tokenizer<boost::char_separator<char>> tokens (inuserInput, sep);
	std::vector<std::string> retVal(tokens.begin(), tokens.end());
	return retVal;
}

std::vector<std::string> CMenu::receiveAndLexUserInput()
{
	std::string inChain;
	do
	{
		std::cout << CURSOR_SIGN;
		getline(std::cin, inChain);
	} while (inChain.size() == ZERO);
	return performLexer(inChain);
}

bool CMenu::isAction(const std::string& zeroArgOfUserInput)
{
	return
		zeroArgOfUserInput == CREATE_MENU or
		zeroArgOfUserInput == CREATE_COMMAND or
		zeroArgOfUserInput == DELETE or
		zeroArgOfUserInput == PRINT or
		zeroArgOfUserInput == HELP;
}

void CMenu::interpretAction(const std::vector<std::string>& userInput)
{
	std::string userAction = userInput[idx::COMMAND_OR_ACTION_NAME];
	if (userAction == CREATE_MENU)
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		{
			if (NULL == findName(userInput[idx::OBJECT_NAME]))
			{
				if (NULL == findCommand(userInput[idx::COMMAND_NAME]))
				{
					children.push_back(new CMenu(userInput[idx::OBJECT_NAME], userInput[idx::COMMAND_NAME]));
					system("cls");
				}
				else
				{
					system("cls");
					std::cout << "Juz jest taka komenda " << userInput[idx::COMMAND_NAME] << END_LINE << END_LINE;
				}
			}
			else
			{
				system("cls");
				std::cout << "Juz jest taka nazwa " << userInput[idx::OBJECT_NAME] << END_LINE << END_LINE;
			}
		}
		std::cout << toStringFlatTree() << END_LINE;
	}
	else if (userAction == CREATE_COMMAND)
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		{
			if (NULL == findName(userInput[idx::OBJECT_NAME]))
			{
				if (NULL == findCommand(userInput[idx::COMMAND_NAME]))
				{
					children.push_back(new CMenuCommand(userInput[idx::OBJECT_NAME], userInput[idx::COMMAND_NAME]));
					system("cls");
				}
				else
				{
					system("cls");
					std::cout << "Juz jest taka komenda " << userInput[idx::COMMAND_NAME] << END_LINE;
				}
			}
			else
			{
				system("cls");
				std::cout << "Juz jest taka nazwa " << userInput[idx::OBJECT_NAME] << END_LINE;
			}
		}
		std::cout << toStringFlatTree() << END_LINE;
	}
	else if (userAction == DELETE)
	{
		if (deleteChildren(userInput[idx::OBJECT_NAME]))
		{
			system("cls");
			std::cout << toStringFlatTree() << END_LINE;
		}
		else
		{
			std::cout << "Nieznaleziono obiektu do skasowania o nazwie "
				<< userInput[idx::OBJECT_NAME] << END_LINE;
		}
	}
	else if (userAction == PRINT)
	{
		system("cls");
		std::cout << toStringTree() << END_LINE;
	}
	else if (userAction == HELP)
	{
		system("cls");
		funs::actionHelp();
	}
}

bool CMenu::validateUserInput(const std::vector<std::string>& userInput, int numberOfExpectedArgs)
{
	if (userInput.size() < numberOfExpectedArgs)
	{
		system("cls");
		std::cout << "Zbyt mala liczba argumentow "
			<< "wpisz 'help' aby zobaczyc liste dostepnych pozycji" << END_LINE << END_LINE;
		return false;
	}
	return true;
}
