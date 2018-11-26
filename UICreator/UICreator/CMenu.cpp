#include "pch.h"
#include <iostream>
#include "CMenu.hpp"
#include "CMenuCommand.hpp"

using namespace actions;
using namespace defaultVals;
using namespace funs;
//
//CMenu::CMenu(const std::string& inMenuName, const std::string& inCommandName)
//	: CMenuItem(inMenuName, inCommandName, OBJECT_TYPE::MENU)
//	, cursor(this)
//{}

CMenu::CMenu(const std::string&  inMenuName, const std::string& inCommandName, CMenuItem* inParent)
	: CMenuItem(inMenuName, inCommandName, OBJECT_TYPE::MENU, inParent)
	, cursor(this)
{}

bool CMenu::run()
{
	while (true)
	{
		std::vector<std::string> userInput = funs::receiveAndLexUserInput();
		if (not cursor->runImpl(userInput))
		{
			return false;
		}
	}
	return true;
}

bool CMenu::runPredefinedCommands(const std::vector<std::vector<std::string>>& inCommands)
{
	for (const auto& it : inCommands)
	{
		if (not cursor->runImpl(it))
		{
			return false;
		}
	}
	return true;
}

bool CMenu::runImpl(const std::vector<std::string>& userInput)
{
	if (userInput.size() == 0)
	{
		system("cls");
		std::cout << funs::actionHelp();
		std::cout << cursor->toStringFlatTree() << END_LINE;
		return true;
	}
	std::string zeroArgOfUserInput = userInput[idx::COMMAND_OR_ACTION_NAME];

	if (zeroArgOfUserInput == BACK)
	{
		system("cls");
		if (NULL == parent)
		{
			return false;
		}
		else
		{
			cursor = dynamic_cast<CMenu*>(parent);
			std::cout << cursor->toStringFlatTree() << END_LINE;
		}
	}
	else if (isAction(zeroArgOfUserInput))
	{
		interpretAction(userInput);
	}
	else if (CMenuItem* command = cursor->findCommand(zeroArgOfUserInput))
	{
		boost::optional<OBJECT_TYPE> UIObjectType = command->getUIObjectType();
		if (UIObjectType)
		{
			switch (*UIObjectType)
			{
				case OBJECT_TYPE::COMMAND:
					//std::cout << "ITS COMMAND " << END_LINE;
					break;
				case OBJECT_TYPE::MENU:
					//std::cout << "ITS MENU " << END_LINE;
					CMenu* nextCursor = dynamic_cast<CMenu*>(command);
					cursor = nextCursor;
					break;
			}
		}
		//return command->runPredefinedCommands({ userInput });
		//command->run();
		std::cout << cursor->toStringFlatTree() << END_LINE;
	}
	else
	{
		system("cls");
		std::cout << zeroArgOfUserInput << ": nie ma takiej pozycji" << END_LINE << END_LINE;
		std::cout << funs::actionHelp();
		std::cout << toStringFlatTree() << END_LINE;
	}
	return true;
}

void CMenu::interpretAction(const std::vector<std::string>& userInput)
{
	const std::string& userAction = userInput[idx::COMMAND_OR_ACTION_NAME];
	if (userAction == CREATE_MENU)
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		{
			if (NULL == cursor->findName(userInput[idx::OBJECT_NAME]))
			{
				if (NULL == cursor->findCommand(userInput[idx::COMMAND_NAME]))
				{
					cursor->children.push_back(
						new CMenu(
							userInput[idx::OBJECT_NAME],
							userInput[idx::COMMAND_NAME],
							this));
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
		std::cout << cursor->toStringFlatTree() << END_LINE;
	}
	else if (userAction == CREATE_COMMAND)
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		{
			if (NULL == cursor->findName(userInput[idx::OBJECT_NAME]))
			{
				if (NULL == cursor->findCommand(userInput[idx::COMMAND_NAME]))
				{
					cursor->children.push_back(new CMenuCommand(userInput[idx::OBJECT_NAME], userInput[idx::COMMAND_NAME]));
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
		std::cout << cursor->toStringFlatTree() << END_LINE;
	}
	else if (userAction == DELETE)
	{
		if (cursor->deleteChildren(userInput[idx::OBJECT_NAME]))
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
		std::cout << cursor->toStringTree() << END_LINE;
	}
	else if (userAction == HELP)
	{
		system("cls");
		std::cout << funs::actionHelp();
		std::cout << toStringFlatTree() << END_LINE;
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
