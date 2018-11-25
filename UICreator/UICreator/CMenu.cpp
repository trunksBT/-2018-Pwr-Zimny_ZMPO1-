#include "pch.h"
#include <iostream>
#include <boost/tokenizer.hpp>

#include "CMenu.hpp"

using namespace defaultVals;
using namespace actions;

CMenu::CMenu(const std::string& inMenuName, const std::string& inuserInputName)
	: CMenuItem(inMenuName, inuserInputName)
{
}

CMenu::~CMenu()
{
}

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
		zeroArgOfUserInput = userInput[0];

		if (isAction(zeroArgOfUserInput))
		{
			interpretAction(userInput);
		}
		else if (CMenuItem* itemWithMatchingCommand = findCommand(zeroArgOfUserInput))
		{
			//itemWithMatchingCommanda
			//itemWithMatchingCommand
		}
		else if (zeroArgOfUserInput == BACK)
		{
			system("cls");
		}
		else
		{
			system("cls");
			std::cout << zeroArgOfUserInput << ": nie ma takiej pozycji" << END_LINE;
			funs::actionHelp();
		}
	} while (zeroArgOfUserInput != BACK);
}

std::vector<std::string> CMenu::performLexer(std::string inuserInput)
{
	boost::char_separator<char> sep(SEPARATOR);
	boost::tokenizer<boost::char_separator<char>> tokens (inuserInput, sep);
	std::vector<std::string> retVal(tokens.begin(), tokens.end());
	return retVal;
} // wziales z neta aby zabezpieczyc sie przed blednymi wejsciami uzytkownika

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
		zeroArgOfUserInput == SELECT or
		zeroArgOfUserInput == PRINT or
		zeroArgOfUserInput == HELP;
}

void CMenu::interpretAction(const std::vector<std::string>& userInput)
{
	std::string userAction = userInput[0];
	if (userAction == CREATE_MENU)
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		{
			if (NULL == findMenu(userInput[1]))
			{
				if (NULL == findCommand(userInput[2]))
				{
					addObject(new CMenu(userInput[idxForInput::MENU_NAME], userInput[2]));
					system("cls");
				}
				else
				{
					system("cls");
					std::cout << "Juz jest taka komenda " << userInput[2] << END_LINE;
				}
			}
			else
			{
				system("cls");
				std::cout << "Juz jest takie menu " << userInput[1] << END_LINE;
			}
		}
		std::cout << toStringFlatTree() << END_LINE;
	}
	else if (userAction == CREATE_COMMAND)
	{
		//if (validateUserInput(userInput, reqNumOfArgsFor::CREATE_MENU))
		//{
		//	if (NULL == findMenu(userInput[1]))
		//	{
		//		if (NULL == findCommand(userInput[2]))
		//		{
		//			addObject(new CMenu(userInput[idxForInput::MENU_NAME], userInput[2]));
		//			system("cls");
		//		}
		//		else
		//		{
		//			system("cls");
		//			std::cout << "Juz jest taka komenda " << userInput[2] << END_LINE;
		//		}
		//	}
		//	else
		//	{
		//		system("cls");
		//		std::cout << "Juz jest takie menu " << userInput[1] << END_LINE;
		//	}
		//}
		//std::cout << toStringFlatTree() << END_LINE;
	}
	else if (userAction == SELECT) // it will be called when objects 
		// is of type CMenu and user will pass the command
	{
		if (validateUserInput(userInput, reqNumOfArgsFor::SELECT))
		{
			CMenuItem* searchedElementInMenu = findMenu(userInput[1]);
			if (NULL != searchedElementInMenu)
			{
				system("cls");
				searchedElementInMenu->run();
			}
			else
			{
				system("cls");
				std::cout << "Nie ma takiego menu " << userInput[1] << END_LINE;
			}
		}
		std::cout << toStringFlatTree() << END_LINE;
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
		std::cout << "Zbyt mala liczba argumentow, wpisz 'help' aby zobaczyc liste dostepnych pozycji" << END_LINE << END_LINE;
		return false;
	}
	return true;
}

void CMenu::interpretCommand(const std::vector<std::string>& userInput)
{
	system("cls");
	std::cout << "Znalazlem komende " << userInput[0] << END_LINE << END_LINE;
	std::cout << toStringFlatTree() << END_LINE;
}
