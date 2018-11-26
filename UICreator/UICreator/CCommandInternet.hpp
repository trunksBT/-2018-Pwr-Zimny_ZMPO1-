#pragma once

#include "CCommand.hpp"

class CCommandInternet : public CCommand
{
public:
	void runCommand() final override;
};

