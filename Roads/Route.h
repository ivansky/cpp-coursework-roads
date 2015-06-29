#pragma once

#include <vector>

#include "Road.h"

class Road;
class City;

class Route
{
private:
	std::vector<Road*> roads;
	std::vector<City*> cities;
	City* from;
	City* last;
	City* to;
public:
	Route(City* from, City* to);
	~Route();
	Route* clone();
	bool addCity(City* step);
	void Route::setRoads(std::vector<Road*> l);
	void Route::setCities(std::vector<City*> l);
	City* getLast();
	float getLength();
	std::vector<std::string> getNames();
};

