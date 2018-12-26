#include "BnBForAnnealing.h"
#include <iostream>
#include <iomanip>
#include <queue>

BnBForAnnealing::BnBForAnnealing()
{
	ReducedGraph.resize(vertex);
	for (int i = 0; i < vertex; i++)
	{
		ReducedGraph[i].resize(vertex);
	}

	path.resize(vertex);

	minCost = 0;

}

BnBForAnnealing::~BnBForAnnealing()
{
	ReducedGraph.clear();
	path.clear();
	minCost = INT_MAX;
}

int BnBForAnnealing::ReduceGraph(std::vector<std::vector<int>> &vector)
{
	int minCost = 0;

	std::vector<int> minRowCost;
	std::vector<int> minColCost;

	int minRow = INT_MAX;

	for (int i = 0; i < vector.size(); i++)
	{
		for (int j = 0; j < vector.size(); j++)
		{
			if (vector[i][j] != -1 && vector[i][j] < minRow)
			{
				minRow = vector[i][j];
			}
		}


		minRowCost.push_back(minRow);

		for (int j = 0; j < vector.size(); j++)
		{
			if (i != j && vector[i][j] != -1)
			{
				vector[i][j] -= minRowCost[i];
			}

		}

		minRow = INT_MAX;
	}

	int minCol = INT_MAX;

	for (int i = 0; i < vector.size(); i++)
	{
		for (int j = 0; j < vector.size(); j++)
		{
			if (vector[j][i] != -1 && vector[j][i] < minCol)
			{
				minCol = vector[j][i];
			}
		}

		minColCost.push_back(minCol);

		for (int j = 0; j < vector.size(); j++)
		{
			if (i != j && vector[j][i] != -1)
			{
				vector[j][i] -= minColCost[i];
			}

		}

		minCol = INT_MAX;
	}

	for (int i = 0; i < vector.size(); i++)
	{
		if (minRowCost[i] == INT_MAX)
		{
			minRowCost[i] = 0;
		}
		if (minColCost[i] == INT_MAX)
		{
			minColCost[i] = 0;
		}

		minCost += minColCost[i] + minRowCost[i];
	}

	return minCost;
}

std::vector<std::vector<int>> BnBForAnnealing::MakeInf(int row, int col, std::vector<std::vector<int>> vector)
{
	std::vector<std::vector<int>> temp = vector;

	for (int i = 0; i < temp.size(); i++)
	{
		temp[row][i] = -1;
		temp[i][col] = -1;
	}

	temp[col][row] = -1;

	return temp;
}

void BnBForAnnealing::PrintPath()
{
	std::cout << this->minCost << std::endl;

	for (int i = 0; i < this->path.size(); i++)
	{
		if (i == this->path.size() - 1)
		{
			std::cout << this->path[i];
		}
		else std::cout << this->path[i] << " -> ";
	}
	std::cout << std::endl;
}

Node BnBForAnnealing::BranchnBound(int source)
{
	Node node;
	minCost = INT_MAX;
	std::vector<std::vector<int>> reducedGraph = this->graphData;
	
	int reductionCost = ReduceGraph(reducedGraph);
	
	std::vector<Node> vertices;

	Node root = { reductionCost, reducedGraph, 0 };
	
	vertices.push_back(root);

	do
	{
		std::sort(vertices.begin(), vertices.end());

		Node currentNode = vertices.back();

		//odwolanie do pierwszego elementu z kloejki
		
		if (currentNode.bound == 0)
		{
			currentNode.currentPath.push_back(0);
		}

		vertices.clear();
		
		currentNode.visited.resize(this->vertex);
		currentNode.visited[currentNode.bound] = true;

		for (int i = 0; i < this->vertex; i++)
		{
			//sprawdzenie czy dany wierzcho³ek nie by³ju¿ odwiedzony
			if (!currentNode.visited[i])
			{
				Node newNode;
				//iniclajizacja zmiennych ze struktury zgodnie z algorytmem
				newNode.NodeReducedGraph = MakeInf(currentNode.bound, i, currentNode.NodeReducedGraph);
				newNode.visited = currentNode.visited;
				newNode.currentPath = currentNode.currentPath;
				newNode.bound = i;
				newNode.currentPath.push_back(i);
				newNode.visited[i] = true;

				newNode.weight = currentNode.NodeReducedGraph[currentNode.bound][i] + currentNode.weight + ReduceGraph(newNode.NodeReducedGraph);

				//dodanie wierzcho³ków do kolejki
				vertices.push_back(newNode);
			}
		}
		this->minCost = currentNode.weight;
		this->path = currentNode.currentPath;
	} while (path.size() < this->vertex);

	//path.push_back(source);
	return node;
}

int BnBForAnnealing::Cost()
{
	int cost = minCost;
	return cost;
}

std::vector<int> BnBForAnnealing::Path()
{
	std::vector<int> temp = path;
	return temp;
}
