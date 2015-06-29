#include "Road.h"

Road::Road(City* a, City* b, float d)
{
	from = a;
	to = b;
	setDistance(d);
}

void Road::setDistance(float d){
	distance = d;
};

float Road::getDistance(){
	return distance;
};

City* Road::getDeparture(){
	return from;
}

City* Road::getDestination(){
	return to;
}

Road::~Road()
{
}
