#include "pch.h"
#include <iostream>
#include "CCommandAla.hpp"
#include "Utils.hpp"

using namespace defaultVals;

bool CCommandAla::runCommand()
{
	system("cls");
	std::cout << "Ala ma kota" << END_LINE << END_LINE;
	return true;
}
