#pragma once
#include <string>

class Entity
{
protected:
	std::string name;
public:
	Entity();
	virtual ~Entity();
	void setName(std::string name);
	std::string getName();
};

