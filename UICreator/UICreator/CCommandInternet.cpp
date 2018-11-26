#include "pch.h"
#include <iostream>
#include "CCommandInternet.hpp"
#include "Utils.hpp"

using namespace defaultVals;

bool CCommandInternet::runCommand()
{
	system("cls");
	std::cout << "Uruchamiam przegladarke internetowa" << END_LINE << END_LINE;
	return true;
}
