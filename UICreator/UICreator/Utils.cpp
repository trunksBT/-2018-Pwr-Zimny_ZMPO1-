#include "pch.h"
#include "Utils.hpp"
#include <iostream>

using namespace defaultVals;
using namespace actions;

namespace funs
{
	void actionHelp()
	{
		std::cout << actions::CREATE_MENU << " MENU_NAME CMD_NAME - To create menu named OBJ_NAME openable via CMD_NAME" << END_LINE;
		std::cout << actions::CREATE_COMMAND << " MENU_NAME CMD_NAME - To create command named OBJ_NAME callable via CMD_NAME" << END_LINE;
		std::cout << actions::DELETE << " OBJ_NAME - To delete menu/command named OBJ_NAME" << END_LINE;
		std::cout << actions::PRINT << " To print all menu with submenus" << END_LINE;
		std::cout << actions::BACK << " To back to previous menu/close app" << END_LINE;
	}
}