#include "Road.h"

Road::Road(City* departure, City* destination, float d)
{
	this->from = departure;
	this->to = destination;
	this->setDistance(d);
}

void Road::setDistance(float d){
	this->distance = d;
};

float Road::getDistance(){
	return this->distance;
};

City* Road::getDeparture(){
	return this->from;
}

City* Road::getDestination(){
	return this->to;
}

Road::~Road()
{
}
