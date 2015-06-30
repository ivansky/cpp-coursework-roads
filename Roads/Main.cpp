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
	City* moscow = addCity(new City("������"));
	City* izhevsk = addCity(new City("������"));
	City* novgorod = addCity(new City("������ ��������"));
	City* kazan = addCity(new City("������"));
	City* saransk = addCity(new City("�������"));
	City* ulyanovsk = addCity(new City("���������"));

	// ������ -> ������ ��������
	moscow->addRoad(novgorod, 417);

	// ������ �������� -> ������
	novgorod->addRoad(kazan, 395);

	// ������ -> ������
	kazan->addRoad(izhevsk, 379);

	// ������ -> �������
	moscow->addRoad(saransk, 656);

	// ������� -> ���������
	saransk->addRoad(ulyanovsk, 231); 

	// ��������� -> ������
	ulyanovsk->addRoad(izhevsk, 573);
	
	printf("������:\n");

	for (unsigned int i = 0; i < cities.size(); ++i){
		printf("%d. %s\n", i, cities[i]->getName().c_str());
	}

	City *from;
	City *to;

	from = moscow;
	to = izhevsk;

	Route* shortlyRoute = from->getRouteTo(to);

	if (shortlyRoute == nullptr){
		printf("���� �� ������!\n");
	}
	else{
		std::vector<std::string> namesList = shortlyRoute->getNames();

		printf("���� �� %s �� %s:\n", from->getName().c_str(), to->getName().c_str());

		unsigned int number = 1;

		for (std::string name : namesList){
			printf("%d. %s\n", number++, name.c_str());
		}

	}

	system("pause");

	return 0;
}