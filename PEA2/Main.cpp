#include "Menu.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	Menu menu;
	menu.menuMain();
	return 0;
}

/*#include <iostream>
#include "Menu.h"
#include <ctime>
#include "SimulatedAnnealing.h"
#include <sstream>

using namespace std;

int main()
{
	srand(time(NULL));
	
	TimeMeasure pomiary;
	Graph* graf;
	SimulatedAnnealing* annealing;
	BnBForAnnealing* bb;

	graf = new Graph();
	annealing = new SimulatedAnnealing();
	bb = new BnBForAnnealing();

	vector<double> czasyAlgorytm;
	vector<double> drogi;
	std::vector<int> tempPath;
	double cool;
	ostringstream ss;
	string str = ss.str();

	/*annealing->ReadAtspFile("ftv47.atsp", 48);
	bb->ReadAtspFile("ftv47.atsp", 48);

	annealing->setStopTime(120);
	bb->BranchnBound(0);
	tempPath = bb->Path();
	
	for (float j = 0.98; j < 0.99; j = j + 0.002)
	{	
		cool = j;
		
		ss << j;

		string nazwaPlikuAlgorytm = "Czasy-Graf48-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf48-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing->SimAnnealing(cool, tempPath, annealing->getStopTime());
			czasyAlgorytm.push_back(annealing->getTime());
			drogi.push_back(annealing->getCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}#1#

	annealing->ReadAtspFile("ftv170.atsp", 171);
	bb->ReadAtspFile("ftv170.atsp", 171);
	annealing->setStopTime(240);
	bb->BranchnBound(0);
	tempPath = bb->Path();

	for (float j = 0.98; j < 0.991; j = j + 0.002)
	{
		cool = j;
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf171-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf171-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing->SimAnnealing(cool, tempPath, annealing->getStopTime());
			czasyAlgorytm.push_back(annealing->getTime());
			drogi.push_back(annealing->getCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	annealing->ReadAtspFile("rbg403.atsp", 403);
	bb->ReadAtspFile("rbg403.atsp", 403);
	annealing->setStopTime(360);
	bb->BranchnBound(0);
	tempPath = bb->Path();

	for (float j = 0.98; j < 0.99; j = j + 0.002)
	{
		cool = j;
		ss << j;
		string nazwaPlikuAlgorytm = "Czasy-Graf404-" + ss.str() + ".txt";
		string nazwaPlikuDrogi = "Drogi-Graf404-" + ss.str() + ".txt";
		for (int i = 0; i < 10; i++)
		{
			annealing->SimAnnealing(cool, tempPath, annealing->getStopTime());
			czasyAlgorytm.push_back(annealing->getTime());
			drogi.push_back(annealing->getCost());
		}
		pomiary.saveToFile(czasyAlgorytm, nazwaPlikuAlgorytm);
		pomiary.saveToFile(drogi, nazwaPlikuDrogi);
		czasyAlgorytm.clear();
		drogi.clear();
	}

	exit(EXIT_SUCCESS);
}*/