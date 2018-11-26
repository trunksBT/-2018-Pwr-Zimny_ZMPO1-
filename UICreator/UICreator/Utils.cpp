#include "pch.h"
#include "Utils.hpp"
#include <iostream>

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
}