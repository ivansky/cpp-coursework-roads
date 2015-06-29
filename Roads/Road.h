#pragma once

#include "City.h"

class City;

class Road
{
private:
	float distance;
	City* from;
	City* to;
public:
	Road(City*, City*, float);
	~Road();
	void setDistance(float);
	float getDistance();
	City* getDeparture();
	City* getDestination();
};

