#pragma once
#include <vector>
#include "Graph.h"
#include "TimeMeasure.h"

struct Node
{
	int weight;
	std::vector<std::vector<int>> NodeReducedGraph;
	int bound;
	std::vector<bool> visited;
	std::vector<int> currentPath;
	friend bool operator < (const Node& other, const Node& second)
	{
		return other.weight > second.weight;
	}
};

class BnBForAnnealing : public Graph
{
private:
	std::vector<std::vector<int>> ReducedGraph;
	int minCost;
	std::vector<int> path;
public:
	BnBForAnnealing();
	~BnBForAnnealing();
	int ReduceGraph(std::vector<std::vector<int>> &vector);
	std::vector<std::vector<int>> MakeInf(int row, int col, std::vector<std::vector<int>> vector);
	void PrintPath();
	Node BranchnBound(int source);
	int Cost();
	std::vector<int> Path();
};
