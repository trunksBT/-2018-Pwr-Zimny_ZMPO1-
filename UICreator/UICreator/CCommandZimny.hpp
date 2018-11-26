#pragma once

#include "CCommand.hpp"

class CCommandZimny : public CCommand
{
public:
	bool runCommand() final override;
};

