#include "pch.h"
#include <algorithm>
#include "CMenuItem.hpp"

using namespace defaultVals;

CMenuItem::CMenuItem(std::string inMenuName, std::string inCommandName)
	: s_command(inCommandName)
	, s_name(inMenuName)
{}

CMenuItem::CMenuItem(std::string inMenuName, std::string inCommandName, OBJECT_TYPE inType)
	: s_command(inCommandName)
	, s_name(inMenuName)
	, objectType(inType)
{}

CMenuItem::CMenuItem(
	std::string inMenuName,
	std::string inCommandName,
	OBJECT_TYPE inType,
	CMenuItem* inParent)
: s_command(inCommandName)
, s_name(inMenuName)
, objectType(inType)
, parent(inParent)
{}

CMenuItem::~CMenuItem()
{
	for (auto& it : children)
	{
		delete it;
		it = NULL;
	}
}

std::string CMenuItem::getName()
{
	return s_name;
}

std::string CMenuItem::getCommandName()
{
	return s_command;
}

CMenuItem* CMenuItem::findName(const std::string& objectName)
{
	for (const auto& child : children)
	{
		if (child->getName() == objectName)
		{
			return child;
		}
	}
	return NULL;
}

CMenuItem* CMenuItem::findCommand(const std::string& commandName)
{
	for (const auto& child : children)
	{
		if (child->getCommandName() == commandName)
		{
			return child;
		}
	}
	return NULL;
}

bool CMenuItem::deleteChildren(const std::string& objectName)
{
	int idxToDel = -1;
	for (int i = 0; i < children.size() && idxToDel == -1; i++)
	{
		if (objectName == children.at(i)->getName())
		{
			idxToDel = i;
		}
	}

	if (-1 < idxToDel)
	{
		const int idxOfLastElem = children.size() - 1;
		if (1 == children.size() // jest jedynym elementem albo
			or idxToDel == idxOfLastElem) // jestem ostatnim elementem
		{
			delete children[idxToDel];
			children.pop_back();
		}
		else // jest gdzieœ poœrodku
		{
			CMenuItem* temp = children.at(idxOfLastElem);
			children[idxOfLastElem] = children[idxToDel];
			children[idxToDel] = temp;

			delete children[idxOfLastElem];
			children.pop_back();
		}
		return true;
	}
	return false;
}

std::string CMenuItem::toString()
{
	return getName() + "(" + getCommandName() + ")";
}

std::string CMenuItem::toStringFlatTree()
{
	std::string retVal(toString());
	retVal += END_LINE;

	for (const auto& it : children)
	{
		retVal += insertIndent(1);
		retVal += it->toString() + END_LINE;
	}
	return retVal;
}

std::string CMenuItem::toStringTree(int indent)
{
	std::string retVal(toString());
	retVal += END_LINE;
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
		retVal += INDENT_OF_SIZE_ONE;
	}
	return retVal;
}

boost::optional<OBJECT_TYPE> CMenuItem::getUIObjectType()
{
	return objectType;
}
