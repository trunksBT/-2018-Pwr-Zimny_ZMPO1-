#include "pch.h"
#include <iostream>
#include "CMenuCommand.hpp"
#include "CCommandAla.hpp"
#include "CCommandInternet.hpp"
#include "Utils.hpp"

using namespace defaultVals;

CMenuCommand::CMenuCommand(std::string inName, std::string inCommandName)
	: CMenuItem(inName, inCommandName)
	, command(NULL)
{
	if (inCommandName == commands::INTERNET)
	{
		command = new CCommandInternet();
	}
	else if (inCommandName == commands::ALA)
	{
		command = new CCommandAla();
	}
}

CMenuCommand::~CMenuCommand()
{
	delete command;
	command = NULL;
}

void CMenuCommand::run()
{
	if (NULL == command)
	{
		std::cout << "Pusta komenda " << getCommandName() << END_LINE << END_LINE;
	}
	else
	{
		command->runCommand();
	}
}
