#include "pch.h"
#include "CCommandZimny.hpp"
#include <iostream>
#include "Utils.hpp"

using namespace defaultVals;

bool CCommandZimny::runCommand()
{
	system("cls");
	std::cout << "Jestem Zimny! " << END_LINE << END_LINE;
	return true;
}
