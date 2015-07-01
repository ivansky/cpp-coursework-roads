#include <iostream>
#include <vector>
#include <limits>
#include <cstddef>

#ifdef _WIN32
	#include <Windows.h>
#endif

#include "Main.h"

#ifdef max
	#undef max
#endif

// Init City list
std::vector<City*> cities;

// Interfaces of support functions
City* addCity(City*);
void printCityList();
void clearConsole();
void sleepEnter();

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


	while (true){

		clearConsole();

		printCityList();

		std::cout << '\n';

		City *from;
		City *to;

		unsigned int fromIndex = 0;
		unsigned int toIndex = 0;

		for (;;) {
			std::cout << "������ ����� �����? : ";
			if (std::cin >> fromIndex && fromIndex >= 0 && fromIndex < cities.size()) {
				break;
			}
			else {
				std::cout << "������� ������ ����� " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}


		for (;;) {
			std::cout << "���� �����? : ";
			if (std::cin >> toIndex && toIndex >= 0 && toIndex < cities.size()) {
				break;
			}
			else {
				std::cout << "������� ������ ����� " << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		if (fromIndex == toIndex){

			std::cout << "�� ��� � ����� ���������� :)" << std::endl;

			sleepEnter();

			continue;

		}

		from = cities[fromIndex];
		to = cities[toIndex];

		Route* shortlyRoute = from->getRouteTo(to);

		std::cout << '\n';

		if (shortlyRoute == nullptr){
			printf("���� �� ������!\n");
		}
		else{
			std::vector<std::string> namesList = shortlyRoute->getNames();

			printf("������ �������� ���� �� %s �� %s:\n", from->getName().c_str(), to->getName().c_str());

			printf("����� ����: %f ��\n", shortlyRoute->getLength());

			unsigned int number = 1;

			for (std::string name : namesList){
				printf("%d. %s\n", number++, name.c_str());
			}

		}

		std::cout << '\n';

		sleepEnter();
	}

	system("pause");

	return 0;
}

City* addCity(City* c){
	cities.push_back(c);
	return c;
};

void printCityList(){
	printf("������:\n");

	for (unsigned int i = 0; i < cities.size(); ++i){
		printf("%d. %s\n", i, cities[i]->getName().c_str());
	}
};

void clearConsole(){
#ifdef _WIN32
	std::system("cls");
#else
	// Assume POSIX
	std::system("clear");
#endif
	std::cout << "Coursework `Roads` by Ivan Martianov. Ver 1.0" << '\n' << std::endl;
};

void sleepEnter() {
	std::cout << "������� Enter, ����� ����������." << std::endl;

	char prev = 0;
	while (1){
		char c = (char)getchar();
		if (c == '\n' && c == prev)
			break;
		prev = c;
	}
};