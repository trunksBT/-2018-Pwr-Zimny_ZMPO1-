#pragma once

#include "CMenuItem.hpp"
#include "CCommand.hpp"

class CMenuCommand : public CMenuItem
{
public:
	CMenuCommand(std::string inName, std::string inCommandName);
	virtual ~CMenuCommand() = default;
	

	void run() final override;

private:
	CCommand* command;
};

// "default" przy destruktorzy znaczy to ze
// kompilator automatycznie wygeneruje destruktor
// który wywo³a destruktor klasy CMenuItem
