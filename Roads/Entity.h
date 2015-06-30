#pragma once
#include <string>

class Entity
{
protected:
	std::string name;
public:
	Entity();
	virtual ~Entity();
	virtual void setName(std::string name);
	virtual std::string getName();
};

