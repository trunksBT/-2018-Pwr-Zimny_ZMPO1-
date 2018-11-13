#pragma once
#include <vector>

class Abstract
{
private:
	std::string name_;

private:
	std::string insertIndent(int multiplier);

protected:
	std::vector<Abstract*> children;
	Abstract* parent = NULL;
	
public:
	std::string getName();
	void addObject(Abstract* inObj);
	virtual void dupa() = 0;
	std::string toStringTree(int indent = 0);
	Abstract* getParent();

	Abstract(std::string inName);
	Abstract(std::string inName, Abstract* inParent);

	virtual ~Abstract();
};

