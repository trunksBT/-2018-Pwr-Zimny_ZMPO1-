#pragma once

#include "Abstract.hpp"

class Concrete : public Abstract
{
public:
	Concrete(std::string name);
	Concrete(std::string name, Abstract* parent);
	virtual ~Concrete();

	virtual void dupa() override;
};

