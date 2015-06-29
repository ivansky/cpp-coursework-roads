#include "City.h"


City::City(std::string __name)
{
	setName(__name);
};
Road* City::addRoad(City* to, float distance){
	return addRoad(to, distance, true);
}

Road* City::addRoad(City* to, float distance, bool back){

	Road* road = new Road(this, to, distance);

	roads.push_back(road);

	if (back){
		to->addRoad(this, distance, false);
	}

	return road;
};

std::vector<Road*> City::getRoads(){
	return roads;
};

Road* City::getRoadTo(City* to){
	for (unsigned int i = 0; i < roads.size(); ++i){
		if (roads[i]->getDestination() == to){
			return roads[i];
		}
	}
	return nullptr;
}

bool City::hasRoadTo(City* to){
	for (unsigned int i = 0; i < roads.size(); ++i){
		if (roads[i]->getDestination() == to){
			return true;
		}
	}
	return false;
}

Route* City::getRouteTo(City* to){
	std::vector<Route*> routes;

	Route* currentRoute;
	Route* shortlyRoute = nullptr;

	City* currentCity;
	City* currentDestination;

	routes.push_back(new Route(this, to));

	unsigned int i, j, size, activeRoutes;

	while (true){

		activeRoutes = 0;

		size = routes.size();

		// Each in Routes List
		for (i = 0; i < size; ++i){

			currentRoute = routes[i];

			currentCity = currentRoute->getLast();

			// If Destination is our target - skip
			if (currentCity == to){
				continue;
			}

			activeRoutes++;

			std::vector<Road*> roadList = currentCity->getRoads();

			// Roads from Last City Point
			for (j = 0; j < roadList.size(); ++j){

				currentDestination = roadList[j]->getDestination();

				if (currentRoute->addCity(currentDestination)){
					currentRoute = currentRoute->clone();
				}
				else{

					delete currentRoute;
					currentRoute = nullptr;

					break;
				}
			
			}

		}

		// If all routes Done - Break it
		if (activeRoutes == 0) break;
	}

	size = routes.size();

	// If havent Routes return NullPtr
	//if (size == 0) return nullptr;

	for (i = 0; i < size; ++i){

		// Check if Destination is Reached
		if (routes[i]->getLast() != to){
			continue;
		}

		// If havent best way yet - set current
		if (shortlyRoute == nullptr){
			shortlyRoute = routes[i];
			continue;
		}

		// If current route length 
		// less then best - replaced it
		if (shortlyRoute->getLength() > routes[i]->getLength()){
			shortlyRoute = routes[i];
		}
	}

	return shortlyRoute;
};

City::~City()
{
}
