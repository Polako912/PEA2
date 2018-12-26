#include "TimeMeasure.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

TimeMeasure::TimeMeasure()
{
	PCFreq = 0.0;
	CounterStart = 0;
}


TimeMeasure::~TimeMeasure()
{
}

double TimeMeasure::getCounter() const
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

void TimeMeasure::startCounting()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart);

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

void TimeMeasure::saveToFile(std::vector<double>& czasy, string filename)
{
	ofstream file;
	//const std::string filename;
	file.open(filename, std::ios::out);

	if (file.good())
	{
		for (int i = 0; i < czasy.size(); i++)
		{
			file << czasy[i] << endl;
		}
	}

	file.close();
}