#include "pch.h"
#include "CMenuCommand.hpp"

CMenuCommand::CMenuCommand()
	: CMenuItem()
	, command_(NULL)
{}

CMenuCommand::~CMenuCommand()
{}

void CMenuCommand::run()
{}