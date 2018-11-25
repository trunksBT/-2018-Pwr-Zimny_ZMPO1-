#include "pch.h"
#include "CMenuCommand.hpp"

CMenuCommand::CMenuCommand(std::string inCommandName)
	: CMenuItem(defaultVals::DEFAULT_STRING_VAL, inCommandName)
{
	//if (inCommandName == )
}

CMenuCommand::~CMenuCommand()
{}

void CMenuCommand::run()
{}