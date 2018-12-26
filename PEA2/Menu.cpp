#include "Menu.h"
#include <iostream>
#include "Graph.h"
#include <string>
#include "BnBForAnnealing.h"
#include <ctime>
#include <chrono>

Menu::Menu()
{
	graph = new Graph();
	sa = new SimulatedAnnealing();
	bb = new BnBForAnnealing();
}

Menu::~Menu()
{
}

void Menu::menuMain() const
{
	int choice = 0;
	std::vector<int> tempPath;
	double maxTime = 0;
	double correctTime;
	clock_t start, end;
	double coolingCoefficient = 0;
	std::string filename;

	do
	{
		std::cout << "1.Wczytaj dane z pliku" << std::endl;
		std::cout << "2.Wprowadz kryterium stopu: " << std::endl;
		std::cout << "3.Wprowadz wspolczynnik zmiany temperatury: " << std::endl;
		std::cout << "4.Uruchom algorytm SW" << std::endl;
		std::cout << "5.Wyjscie" << std::endl;
		std::cin.clear();
		std::cout << "Wybor: " << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			ChooseFile();
			break;
		case 2:
			std::cout << "Podaj kryterium stopu: " << std::endl;
			std::cin >> maxTime;
			break;
		case 3:
			std::cout << "Podaj wspolczynnik chlodzenia:" << std::endl;
			std::cin >> coolingCoefficient;
			sa->setCooling(coolingCoefficient);
			break;
		case 4:
			start = clock();
			bb->BranchnBound(0);
			tempPath = bb->Path();
			end = clock();
			if ((double(end - start) / CLOCKS_PER_SEC) < maxTime)
			{
				correctTime = maxTime - (double(end - start) / CLOCKS_PER_SEC);
				sa->SimAnnealing(maxTime, tempPath, correctTime);
				sa->DisplayCost();
				sa->DispalyPath();
				sa->DisplayProperties(coolingCoefficient);
			}
			else
			{
				std::cout << "Krtyerium stopu zostalo zlamane, wynik jest na podstawie algorytmu zachalannego" << std::endl;
				bb->PrintPath();
			}
			break;
		case 5:
			exit(EXIT_SUCCESS);
		default:
			system("cls");
			break;
		}
	}
	while (true);
}

void Menu::ChooseFile() const
{
	int choice;
	std::cout << "Ktory plik otworzyc?" << std::endl
		<< "1. ftv47.atsp" << std::endl
		<< "2. ftv170.atsp" << std::endl
		<< "3. rbg403.atsp" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		sa->ReadAtspFile("ftv47.atsp", 48);
		bb->ReadAtspFile("ftv47.atsp", 48);
		break;
	case 2:
		sa->ReadAtspFile("ftv170.atsp", 171);
		bb->ReadAtspFile("ftv170.atsp", 171);
		break;
	case 3:
		sa->ReadAtspFile("rbg403.atsp", 403);
		bb->ReadAtspFile("rbg403.atsp", 403);
		break;
	default:
		break;
	}
}
