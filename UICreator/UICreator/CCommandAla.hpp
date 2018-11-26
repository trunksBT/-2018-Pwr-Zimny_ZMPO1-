#pragma once

#include "CCommand.hpp"

class CCommandAla : public CCommand
{
public:
	void runCommand() final override;
};

