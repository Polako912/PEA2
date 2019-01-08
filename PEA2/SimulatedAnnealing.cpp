#include "SimulatedAnnealing.h"
#include <iostream>
#include "BnBForAnnealing.h"
#include <iomanip>
#include <chrono>
#include "TimeMeasure.h"


SimulatedAnnealing::SimulatedAnnealing()
{
	startTemperature = 5;
	path.resize(vertex);
	minCost = 0;
}


SimulatedAnnealing::~SimulatedAnnealing()
{
	path.clear();
	minCost = INT_MAX;
}

void SimulatedAnnealing::SimAnnealing(int maxTime, std::vector<int> startPath)
{
	clock_t start, end;
	start = clock();
	std::vector<int> tempVector = startPath;
	double temperature = CalculateTemperature();
	int minCurrentCost = CalculateCost(tempVector);

	do
	{
		for (auto i = 0; i < this->vertex; i++)
		{
			std::vector<int> shuffled = ShuffleVertices(tempVector);
			int currentCost = CalculateCost(shuffled);

			if (currentCost < minCurrentCost)
			{
				tempVector = shuffled;
				minCurrentCost = currentCost;
			}
			else if ((static_cast<float>(rand()) / RAND_MAX) < CalculateProbability(minCurrentCost, currentCost, temperature))
			{
				tempVector = shuffled;
				minCurrentCost = currentCost;
			}
		}
		static_cast<double>(temperature = temperature * getCooling());
		end = clock();
	} while (getTime(end, start) <= maxTime);

	path = tempVector;
	minCost = minCurrentCost;

	std::cout << std::endl;
	
	std::cout << "Czas wykoania:" << std::endl;
	std::cout << maxTime<< "s" << std::endl;
	
}



std::vector<int> SimulatedAnnealing::ShuffleVertices(std::vector<int> vector)
{
	std::vector<int> temp = vector;

	int x, y;

	do
	{
		x = rand() % vertex;
		y = rand() % vertex;
	}
	while (x == y);

	std::swap(temp.at(x), temp.at(y));

	return temp;
}

int SimulatedAnnealing::CalculateCost(std::vector<int> vector)
{
	int cost = 0;

	for(auto i = 0; i < vector.size() - 1; i++)
	{
		cost += graphData[vector.at(i)][vector.at(i + 1)];
	}

	cost += graphData[vector.at(vector.size() - 1)][vector.at(0)];

	return cost;
}

int SimulatedAnnealing::CalculateProbability(int newCost, int oldCost, double temperature )
{
	float result;

	result = (exp(-(static_cast<float>((newCost - oldCost) / temperature))));

	return result;
}

int SimulatedAnnealing::CalculateTemperature()
{
	return abs((getMaxDistance() - getMinDistance()* this->vertex));
}

void SimulatedAnnealing::DisplayCost()
{
	std::cout << "Wartosc drogi:" << std::endl;
	std::cout << this->minCost << std::endl;
}

void SimulatedAnnealing::DispalyPath()
{
	int temp = 0;

	for (auto i = 0; i < this->path.size(); i++)
	{
		if (i == this->path.size() - 1)
		{
			std::cout << this->path[i];
		}
		else std::cout << this->path[i] << " -> ";
	}

	std::cout << std::endl;
}

void SimulatedAnnealing::DisplayProperties(double coolingCoefficient)
{
	std::cout << "Temperatura poczatkowa: " << std::endl;
	std::cout << CalculateTemperature() << std::endl;
	std::cout << "Wspolczynnik chlodzenia: " << std::endl;
	std::cout << static_cast<double>(coolingCoefficient) << std::endl;
}

int SimulatedAnnealing::getCost()
{
	return minCost;
}

int SimulatedAnnealing::getCooling()
{
	return coolingCoefficient;
}

void SimulatedAnnealing::setCooling(int cooling)
{
	coolingCoefficient = cooling;
}

double SimulatedAnnealing::getTime(double a, double b)
{
	return (double(a - b) / CLOCKS_PER_SEC);
}
