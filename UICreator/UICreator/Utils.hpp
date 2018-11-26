#pragma once

#include <string>
#include <vector>

namespace reqNumOfArgsFor
{
	constexpr int CREATE_MENU = 3;
	constexpr int CREATE_COMMAND = 3;
}

namespace actions
{
	static const std::string BACK = "back";
	static const std::string CREATE_MENU = "createMenu";
	static const std::string CREATE_COMMAND = "createCommand";
	static const std::string DELETE = "delete";
	static const std::string HELP = "help";
	static const std::string PRINT = "print";
}

namespace commands
{
	static const std::string INTERNET = "internet";
	static const std::string ALA = "ala";
}

namespace defaultVals
{
	static const int ZERO = 0;
	static const std::string CURSOR_SIGN = ":- ";
	static const char* SPACE_AS_SEPARATOR = " ";  // wskaznik na tablice znakow
	static const char* END_LINE = "\n";
	static const char* INDENT_OF_SIZE_ONE = "---";
}

namespace funs
{
	std::string actionHelp();
	std::vector<std::string> performLexer(std::string inuserInput);
	std::vector<std::string> receiveAndLexUserInput();
	bool validateUserInput(const std::vector<std::string>& userInput, int numberOfExpectedArgs);
}

namespace idx
{
	static const int COMMAND_OR_ACTION_NAME = 0;
	static const int OBJECT_NAME = 1;
	static const int COMMAND_NAME = 2;
}
