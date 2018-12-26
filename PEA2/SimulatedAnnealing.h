#pragma once
#include "BnBForAnnealing.h"
#include "TimeMeasure.h"

class SimulatedAnnealing : public BnBForAnnealing
{
private:
	std::vector<int> path;
	int minCost;
	double startTemperature;
	double coolingCoefficient;

public:
	SimulatedAnnealing();
	~SimulatedAnnealing();
	void SimAnnealing(int startCost, std::vector<int> startPath, double selectedTime);
	std::vector<int> ShuffleVertices(std::vector<int> vector);
	int CalculateCost(std::vector<int> vector);
	int CalculateProbability(int newCost, int oldCost, double temperature);
	void DisplayCost();
	void DispalyPath();
	void DisplayProperties(double coolingCoefficient);
	int getCost();
	int getCooling();
	void setCooling(int cooling);
	double getTime(double a, double b);
};

