#pragma once

#include "CMenuItem.hpp"
#include "CCommand.hpp"

class CMenuCommand : public CMenuItem
{
public:
	CMenuCommand(std::string inCommandName);
	virtual ~CMenuCommand();

	void run() final override;

private:
	CCommand* command_;
};
