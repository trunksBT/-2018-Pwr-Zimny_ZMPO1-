#pragma once

#include "CCommand.hpp"

class CCommandInternet : public CCommand
{
public:
	bool runCommand() final override;
};

