#pragma once

#include <string>
#include <vector>
#include <boost/optional.hpp>
#include "Utils.hpp"

class CMenuItem
{
public:
	CMenuItem(std::string inMenuName, std::string inCommandName);

	virtual ~CMenuItem();

	virtual bool run() = 0;
	virtual bool runPredefinedCommands(
		const std::vector<std::vector<std::string>>& inCommands) = 0;
	boost::optional<OBJECT_TYPE> getUIObjectType();
	std::string toStringFlatTree();

protected:
	CMenuItem(
		std::string inMenuName,
		std::string inCommandName,
		OBJECT_TYPE inType);

	CMenuItem(
		std::string inMenuName,
		std::string inCommandName,
		OBJECT_TYPE inType,
		CMenuItem* inParent);

protected:
	std::string getName();
	std::string getCommandName();

	CMenuItem* findName(const std::string& objectName);
	CMenuItem* findCommand(const std::string& commandName);

	bool deleteChildren(const std::string& objectName);

	std::string toString();
	std::string toStringTree(int indent = 0);
	std::string insertIndent(int multiplier);

	std::vector<CMenuItem*> children;
	boost::optional<OBJECT_TYPE> objectType;
	CMenuItem* parent;

private:
	std::string s_name;
	std::string s_command;
};
