#pragma once

class CCommand
{
public:
	CCommand() {};
	virtual ~CCommand() {};

	virtual void runCommand() = 0;
};