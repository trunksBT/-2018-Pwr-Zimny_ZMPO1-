#include "pch.h"
#include "CMenuItem.hpp"

using namespace defaultVals;

CMenuItem::CMenuItem(std::string inMenuName, std::string inCommandName)
	: s_command(inCommandName)
	, s_name(inMenuName)
{
}

CMenuItem::~CMenuItem()
{
	parent = NULL;
	for (const auto& it : children)
	{
		delete it;
	}
}

std::string CMenuItem::getMenuName()
{
	return s_name;
}

std::string CMenuItem::getCommandName()
{
	return s_command;
}

void CMenuItem::addObject(CMenuItem* inObj)
{
	children.push_back(inObj);
}

CMenuItem* CMenuItem::findMenu(std::string menuName)
{
	for (const auto& child : children)
	{
		if (child->getMenuName() == menuName)
		{
			return child;
		}
	}
	return NULL;
}

std::string CMenuItem::toString()
{
	return getMenuName() + "(" + getCommandName() + ")";
}

std::string CMenuItem::toStringFlatTree()
{
	std::string retVal(toString());
	retVal += "\n";

	for (const auto& it : children)
	{
		retVal += insertIndent(1);
		retVal += it->toString() + '\n';
	}
	return retVal;
}

std::string CMenuItem::toStringTree(int indent)
{
	std::string retVal(toString());
	retVal += "\n";
	++indent;
	for (const auto& it : children)
	{
		retVal += insertIndent(indent);
		retVal += it->toStringTree(indent);
	}
	return retVal;
}

std::string CMenuItem::insertIndent(int multiplier)
{
	std::string retVal;
	for (int i = 0; i < multiplier; i++)
	{
		retVal += "----";
	}
	return retVal;
}
