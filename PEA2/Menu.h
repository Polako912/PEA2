#pragma once
#include "Graph.h"
#include "SimulatedAnnealing.h"
#include "BnBForAnnealing.h"
#include "TimeMeasure.h"

class Menu
{
	Graph* graph;
	SimulatedAnnealing* sa;
	BnBForAnnealing* bb;
	TimeMeasure time;
	
public:
	Menu();
	~Menu();
	void menuMain() const;
	void ChooseFile() const;
	//void TestMenu() const;
};
