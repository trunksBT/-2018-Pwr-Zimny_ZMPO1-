#pragma once

#include "CMenuItem.hpp"
#include "CCommand.hpp"

class CMenuCommand : public CMenuItem
{
public:
	CMenuCommand();
	virtual ~CMenuCommand();

	void run() final override;

private:
	CCommand* command_;
};
