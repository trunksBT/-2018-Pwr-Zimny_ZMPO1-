#include "pch.h"
#include <iostream>
#include "CMenu.hpp"
#include "CMenuCommand.hpp"

using namespace actions;
using namespace defaultVals;
using namespace funs;

CMenu::CMenu(const std::string& inMenuName, const std::string& inuserInputName)
	: CMenuItem(inMenuName, inuserInputName)
{}

void CMenu::run()
{
	std::string zeroArgOfUserInput;
	do
	{
		std::vector<std::string> userInput = funs::receiveAndLexUserInput();
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

void CMenu::interpretAction(const std::vector<std::string>& userInput)
{
	const std::string& userAction = userInput[idx::COMMAND_OR_ACTION_NAME];
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

bool CMenu::isAction(const std::string& zeroArgOfUserInput)
{
	return
		zeroArgOfUserInput == CREATE_MENU or
		zeroArgOfUserInput == CREATE_COMMAND or
		zeroArgOfUserInput == DELETE or
		zeroArgOfUserInput == PRINT or
		zeroArgOfUserInput == HELP;
}
