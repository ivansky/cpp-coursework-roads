#include "Entity.h"


Entity::Entity()
{
}

void Entity::setName(std::string __name){
	name = __name;
};

std::string Entity::getName(){
	return name;
};

Entity::~Entity()
{
}
