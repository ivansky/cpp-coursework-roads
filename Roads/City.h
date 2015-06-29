#pragma once

#include <string>
#include <vector>
#include "Entity.h"
#include "Road.h"
#include "Route.h"

class Road;
class Entity;
class Route;

class City :
	public Entity
{
private:
	std::vector<Road*> roads;
public:
	City(std::string);
	virtual ~City();
	Road* addRoad(City* to, float distance);
	Road* addRoad(City* to, float distance, bool back);
	Route* getRouteTo(City*);
	bool hasRoadTo(City*);
	std::vector<Road*> getRoads();
	Road* getRoadTo(City* to);
};

