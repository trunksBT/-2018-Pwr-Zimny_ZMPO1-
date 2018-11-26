#include "pch.h"
#include "CCommand.hpp"
#include <iostream>
#include "Utils.hpp"

using namespace defaultVals;

bool CCommand::runCommand()
{
	std::cout << "Komenda domyslna" << END_LINE << END_LINE;
	return true;
}
