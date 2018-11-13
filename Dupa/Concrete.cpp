#include "pch.h"
#include "Concrete.hpp"
#include <iostream>


Concrete::Concrete(std::string name)
	: Abstract(name)
{
}

Concrete::Concrete(std::string name, Abstract* parent)
	: Abstract(name, parent)
{
}

void Concrete::dupa()
{
	std::cout << "Concrete " << __func__ << std::endl;
	std::cout << "Number of children " << this->children.size();
}

Concrete::~Concrete()
{
}
