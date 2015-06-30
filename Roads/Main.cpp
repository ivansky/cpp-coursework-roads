#include <iostream>
#include <vector>

#ifdef _WIN32
	#include <Windows.h>
#endif

#include "Main.h"

std::vector<City*> cities;

City* addCity(City* c){
	cities.push_back(c);
	return c;
}

int main()
{

	#ifdef _WIN32
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
	#endif

	setlocale(LC_ALL, "ru_RU.CP1251");
	setlocale(LC_CTYPE, "ru_RU.CP1251");

	// Main City
	City* moscow = addCity(new City("Москва"));
	City* izhevsk = addCity(new City("Ижевск"));
	City* novgorod = addCity(new City("Нижний Новгород"));
	City* kazan = addCity(new City("Казань"));
	City* saransk = addCity(new City("Саранск"));
	City* ulyanovsk = addCity(new City("Ульяновск"));

	// Москва -> Нижний Новгород
	moscow->addRoad(novgorod, 417);

	// Нижний Новгород -> Казань
	novgorod->addRoad(kazan, 395);

	// Казань -> Ижевск
	kazan->addRoad(izhevsk, 379);

	// Москва -> Саранск
	moscow->addRoad(saransk, 656);

	// Саранск -> Ульяновск
	saransk->addRoad(ulyanovsk, 231); 

	// Ульяновск -> Ижевск
	ulyanovsk->addRoad(izhevsk, 573);
	
	printf("Города:\n");

	for (unsigned int i = 0; i < cities.size(); ++i){
		printf("%d. %s\n", i, cities[i]->getName().c_str());
	}

	City *from;
	City *to;

	from = moscow;
	to = izhevsk;

	Route* shortlyRoute = from->getRouteTo(to);

	if (shortlyRoute == nullptr){
		printf("Путь не найден!\n");
	}
	else{
		std::vector<std::string> namesList = shortlyRoute->getNames();

		printf("Путь от %s до %s:\n", from->getName().c_str(), to->getName().c_str());

		unsigned int number = 1;

		for (std::string name : namesList){
			printf("%d. %s\n", number++, name.c_str());
		}

	}

	system("pause");

	return 0;
}