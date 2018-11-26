#include "pch.h"
#include "CMenuCommand.hpp"
#include "CCommandAla.hpp"
#include "CCommandInternet.hpp"

CMenuCommand::CMenuCommand(std::string inName, std::string inCommandName)
	: CMenuItem(inName, inCommandName)
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

void CMenuCommand::run()
{
	command->runCommand();
}