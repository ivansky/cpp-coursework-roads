#include "City.h"

City::City(std::string __name)
{
	setName(__name);
};

Road* City::addRoad(City* to, float distance){
	return this->addRoad(to, distance, true);
}

Road* City::addRoad(City* to, float distance, bool back){

	// If road already exists : return found
	for (Road* road : this->roads){
		if (road->getDestination() == to){
			road->setDistance(distance); // Update Distance Value
			return road;
		}
	}

	Road* road = new Road(this, to, distance);

	this->roads.push_back(road);

	// Add back road if it necessary
	if (back)
		to->addRoad(this, distance, false);

	return road;
};


Road* City::getRoadByIndex(unsigned int index){
	return roads[index];
};

unsigned int City::getRoadsCount(){
	return roads.size();
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
	for (Road* road : roads){
		if (road->getDestination() == to){
			return true;
		}
	}
	return false;
}

Route* City::getRouteTo(City* to){
	
	std::vector<Route*> routes;

	Route* shortlyRoute = nullptr;
	City* currentDestination;

	// Add Departure City
	routes.push_back(new Route(this, to));

	// Define Count of Routes in action
	unsigned int activeRoutes = 0;

	while (true){

		activeRoutes = 0;

		// Each in Routes List
		for (unsigned int i = 0; i < routes.size(); ++i){

			Route* currentRoute = *(routes.begin() + i);

			City* currentCity = currentRoute->getLast();

			// If Destination is our target - skip
			if (currentCity == to){
				continue;
			}

			activeRoutes++;

			std::vector<Road*> roadList = currentCity->getRoads();

			unsigned int roadSize = currentCity->getRoads().size();

			unsigned int acceptedRoads = 0;

			// Roads from Last City Point
			for (std::vector<Road*>::size_type r = 0; r < roadSize; ++r){

				currentDestination = roadList[r]->getDestination();

				Route* cloneRoute = currentRoute->clone();

				if (currentRoute->addCity(currentDestination)){

					acceptedRoads++;

				}
				else{

					delete currentRoute;

					routes.erase(routes.begin() + i);

				}

				if (r < roadSize - 1)
					routes.push_back(cloneRoute);

				currentRoute = cloneRoute;
			
			}

		}

		// If all routes Done - Break it
		if (activeRoutes == 0) break;
	}

	bool firstRoute = true;

	for (Route* route : routes){
		
		// Check if Destination is Reached
		if (!route->isDone()){
			continue;
		}

		// If havent best way yet - set current
		if (firstRoute){
			shortlyRoute = route;
			firstRoute = false;
			continue;
		}

		// If current route length 
		// less then best - replaced it
		if (shortlyRoute->getLength() > route->getLength()){
			shortlyRoute = route;
		}

	}

	return shortlyRoute;
};

City::~City()
{
}
