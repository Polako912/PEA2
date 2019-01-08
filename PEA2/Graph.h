#pragma once
#include <vector>

class Graph
{
protected:
	int vertex;
	std::vector<std::vector<int>> graphData;
	int minDistance;
	int maxDistance;

public:
	Graph();
	~Graph();

	void Display();
	void clearGraph();
	void ReadAtspFile(std::string filename, int number);
	void ReadFromFile(std::string filename);
	int getMaxDistance();
	void setMaxDistance(int number);
	int getMinDistance();
	void setMinDistance(int number);
};