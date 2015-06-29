#include "Route.h"


Route::Route(City* __from, City* __to)
{
	from = __from;
	last = __from;
	to = __to;

	addCity(from);
}

void Route::setRoads(std::vector<Road*> l){
	roads = std::vector<Road*>(l.begin(), l.end());
}

void Route::setCities(std::vector<City*> l){
	cities = std::vector<City*>(l.begin(), l.end());
}

City* Route::getLast(){
	return last;
}

std::vector<std::string> Route::getNames(){

	std::vector<std::string> names;

	names.push_back(from->getName());

	for (unsigned int i = 0; i < roads.size(); ++i){
		names.push_back(roads[i]->getDestination()->getName());
	}

	return names;
}

float Route::getLength(){
	float result = 0;

	for (unsigned int i = 0; i < roads.size(); ++i){
		result += roads[i]->getDistance();
	}

	return result;
}

bool Route::addCity(City* step){
	const unsigned int countCity = cities.size();

	for (unsigned int i = 0; i < countCity; ++i){
		if (cities[i] == step) return false;
	}

	if (!last->hasRoadTo(step)){
		return false;
	}

	roads.push_back(last->getRoadTo(step));

	cities.push_back(step);

	return true;
}

Route* Route::clone(){
	Route* cloned = new Route(from, to);
	cloned->setRoads(roads);
	cloned->setCities(cities);
	return cloned;
}


Route::~Route()
{
}
