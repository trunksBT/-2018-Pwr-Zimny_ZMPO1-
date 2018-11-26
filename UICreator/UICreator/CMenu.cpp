#include "pch.h"
#include <iostream>
#include "CMenu.hpp"
#include "CMenuCommand.hpp"

using namespace actions;
using namespace defaultVals;
using namespace funs;

CMenu::CMenu(const std::string&  inMenuName, const std::string& inCommandName, CMenuItem* inParent)
	: CMenuItem(inMenuName, inCommandName, OBJECT_TYPE::MENU, inParent)
	, isAfterReceivedFirstCommand(false)
	, cursor(this)
{}

bool CMenu::run()
{
	while (true)
	{
		std::vector<std::string> userInput = funs::receiveAndLexUserInput();
		if (isAfterReceivedFirstCommand)
		{
			cursor = dynamic_cast<CMenu*>(cursor)->runImpl(userInput);
		}
		else
		{
			cursor = runImpl(userInput);
			isAfterReceivedFirstCommand = true;
		}
		if (NULL == cursor)
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
		if (isAfterReceivedFirstCommand)
		{
			cursor = dynamic_cast<CMenu*>(cursor)->runImpl(it);
		}
		else
		{
			cursor = runImpl(it);
			isAfterReceivedFirstCommand = true;
		}
		if (NULL == cursor)
		{
			return false;
		}
	}
	return true;
}

CMenuItem* CMenu::runImpl(const std::vector<std::string>& userInput)
{
	if (userInput.size() == 0)
	{
		system("cls");
		std::cout << funs::actionHelp();
		std::cout << toStringFlatTree() << END_LINE;
		return NULL;
	}
	std::string zeroArgOfUserInput = userInput[idx::COMMAND_OR_ACTION_NAME];

	if (zeroArgOfUserInput == BACK)
	{
		system("cls");
		if (NULL == parent)
		{
			return NULL;
		}
		else
		{
			std::cout << parent->toStringFlatTree() << END_LINE;
			return parent;
		}
	}
	else if (isAction(zeroArgOfUserInput))
	{
		return interpretAction(userInput);
	}
	else if (CMenuItem* itemWithMatchedByNameCommand = findCommand(zeroArgOfUserInput))
	{
		return interpretCommand(itemWithMatchedByNameCommand);
	}
	else
	{
		system("cls");
		std::cout << zeroArgOfUserInput << ": nie ma takiej pozycji" << END_LINE << END_LINE;
		std::cout << funs::actionHelp();
		std::cout << toStringFlatTree() << END_LINE;
		return this;
	}
}

CMenuItem* CMenu::interpretCommand(CMenuItem* itemWithMatchedByNameCommand)
{
	system("cls");
	boost::optional<OBJECT_TYPE> UIObjectType = itemWithMatchedByNameCommand->getUIObjectType();
	if (UIObjectType)
	{
		switch (*UIObjectType)
		{
		case OBJECT_TYPE::COMMAND:
			itemWithMatchedByNameCommand->run();
			std::cout << toStringFlatTree() << END_LINE;
			return this;
		case OBJECT_TYPE::MENU:
			std::cout << itemWithMatchedByNameCommand->toStringFlatTree() << END_LINE;
			return itemWithMatchedByNameCommand;
		}
	}
	std::cout << "Blad programowanie, nieuzupelniony typ" << END_LINE;
	return NULL;
}

CMenuItem* CMenu::interpretAction(const std::vector<std::string>& userInput)
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
					children.push_back(
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
		std::cout << funs::actionHelp();
		std::cout << toStringFlatTree() << END_LINE;
	}
	return this;
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
