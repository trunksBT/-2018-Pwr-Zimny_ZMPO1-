#include "pch.h"
#include <iostream>
#include "CMenuCommand.hpp"
#include "CCommandAla.hpp"
#include "CCommandInternet.hpp"
#include "CCommandZimny.hpp"
#include "Utils.hpp"

using namespace defaultVals;

CMenuCommand::CMenuCommand(std::string inName, std::string inCommandName)
	: CMenuItem(inName, inCommandName, OBJECT_TYPE::COMMAND)
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
	else if (inCommandName == commands::ZIMNY)
	{
		command = new CCommandZimny();
	}
}

CMenuCommand::~CMenuCommand()
{
	delete command;
	command = NULL;
}

bool CMenuCommand::run()
{
	if (NULL == command)
	{
		std::cout << "Pusta komenda " << getCommandName() << END_LINE << END_LINE;
	}
	else
	{
		command->runCommand();
	}
	return true;
}

bool CMenuCommand::runPredefinedCommands(const std::vector<std::vector<std::string>>& inCommands)
{
	return true;
}
