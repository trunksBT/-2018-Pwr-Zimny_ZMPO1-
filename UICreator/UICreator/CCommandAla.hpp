#pragma once

#include "CCommand.hpp"

class CCommandAla : public CCommand
{
public:
	bool runCommand() final override;
};

