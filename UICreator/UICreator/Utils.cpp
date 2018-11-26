#include "pch.h"
#include <iostream>
#include <boost/tokenizer.hpp>

#include "Utils.hpp"

using namespace defaultVals;
using namespace actions;

namespace funs
{
	void actionHelp()
	{
		std::cout << "OBJ_NAME(CMD_NAME)" << END_LINE << END_LINE;
		std::cout << "Calling Commands " << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << " CMD_NAME -  If MENU -> Open Menu , elif COMMAND -> Call Command" << END_LINE << END_LINE;
		std::cout << "Executing Actions " << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << actions::CREATE_MENU << " OBJ_NAME CMD_NAME -  Create menu named OBJ_NAME openable via CMD_NAME" << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << actions::CREATE_COMMAND << " OBJ_NAME CMD_NAME -  Create command named OBJ_NAME callable via CMD_NAME" << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << actions::DELETE << " OBJ_NAME -  Delete menu/command named OBJ_NAME" << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << actions::PRINT << " -  Print all menu with submenus" << END_LINE;
		std::cout << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << actions::BACK << " -  Back to previous menu/close app" << END_LINE << END_LINE;
	}

	std::vector<std::string> performLexer(std::string inuserInput)
	{
		boost::char_separator<char> sep(SPACE_AS_SEPARATOR);
		boost::tokenizer<boost::char_separator<char>> tokens(inuserInput, sep);
		std::vector<std::string> retVal(tokens.begin(), tokens.end());
		return retVal;
	}

	std::vector<std::string> receiveAndLexUserInput()
	{
		std::string inChain;
		do
		{
			std::cout << CURSOR_SIGN;
			getline(std::cin, inChain);
		} while (inChain.size() == ZERO);
		return performLexer(inChain);
	}

	bool validateUserInput(const std::vector<std::string>& userInput, int numberOfExpectedArgs)
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
}
