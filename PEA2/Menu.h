#pragma once
#include "Graph.h"
#include "SimulatedAnnealing.h"
#include "BnBForAnnealing.h"
#include "TimeMeasure.h"

class Menu
{
	SimulatedAnnealing* sa;
	BnBForAnnealing* bb;
	
public:
	Menu();
	~Menu();
	void menuMain() const;
	void ChooseFile() const;
};
