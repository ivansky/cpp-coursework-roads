#include "Route.h"


Route::Route(City* __from, City* __to)
{
	this->from = __from;
	this->last = __from;
	this->to = __to;
	this->cities.push_back(this->from);
}

bool Route::isDone(){
	return (this->last == this->to);
}

void Route::setRoads(std::vector<Road*> l){
	this->roads = std::vector<Road*>(l.begin(), l.end());
}

void Route::setCities(std::vector<City*> l){
	this->cities = std::vector<City*>(l.begin(), l.end());
}

unsigned int Route::getCityCount(){
	return this->cities.size();
}

City* Route::getLast(){
	return this->last;
}

std::vector<std::string> Route::getNames(){

	std::vector<std::string> names;

	names.push_back(from->getName());

	for (Road* road : roads){
		names.push_back(road->getDestination()->getName());
	}

	return names;
}

float Route::getLength(){
	float result = 0;

	for (Road* road : roads){
		result += road->getDistance();
	}

	return result;
}

bool Route::addCity(City* step){
	
	// If city already visited : return false
	for (City* city : cities){
		if (city == step)
			return false;
	}

	if (last == step || !last->hasRoadTo(step)){
		return false;
	}

	Road* road = last->getRoadTo(step);

	roads.push_back(road);

	cities.push_back(step);

	last = step;
	
	return true;
}

Route* Route::clone(){

	Route* cloned = new Route(from, to);

	for (City* el : cities){
		if(el != from) 
			cloned->addCity(el);
	}

	return cloned;
}


Route::~Route()
{
}
