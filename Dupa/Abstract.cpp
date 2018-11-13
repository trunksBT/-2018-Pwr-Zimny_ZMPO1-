#include "pch.h"
#include "Abstract.hpp"
#include <iostream>
#include <string>

Abstract::Abstract(std::string inName)
{
	name_ = inName;
}

Abstract::Abstract(std::string inName, Abstract* inParent)
{
	name_ = inName;
	parent = inParent;
}

void Abstract::addObject(Abstract* inObj)
{
	children.push_back(inObj);
}

std::string Abstract::getName()
{
	return name_;
}

std::string Abstract::toStringTree(int indent)
{
	std::string retVal(getName()+'\n');
	++indent;
	for(const auto& it: children)
	{
		retVal += insertIndent(indent);
		retVal += it->toStringTree(indent);
	}
	return retVal;
}

std::string Abstract::insertIndent(int multiplier)
{
	std::string retVal;
	for (int i = 0; i < multiplier; i++)
	{
		retVal += "----";
	}
	return retVal;
}

Abstract* Abstract::getParent()
{
	return parent;
}

Abstract::~Abstract()
{
	parent = NULL;
	for (const auto& it : children)
	{
		delete it;
	}
}
