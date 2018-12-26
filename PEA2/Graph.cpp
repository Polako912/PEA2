#include <iostream>
#include "Graph.h"
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <sstream>

Graph::Graph()
{
	vertex = 0;
}

Graph::~Graph()
{
	clearGraph();
}

void Graph::Display()
{
	int temp = 0;

	for (auto i = 0; i < graphData.size(); i++)
	{
		for (auto j = 0; j < graphData[i].size(); j++)
		{
			std::cout << std::setw(5) << graphData[i][j] << " ";
			temp++;

			if(temp == vertex)
			{
				std::cout << std::endl;
				temp = 0;
			}
			
		}
	}

	std::cout << std::endl;
}

void Graph::clearGraph()
{
	graphData.clear();
}

void Graph::ReadAtspFile(std::string filename, int number)
{
	std::fstream file;
	file.open(filename, std::ios::in);

	if(file.good())
	{
		std::string line;

		vertex = number;

		graphData.resize(vertex);
		for (auto i = 0; i < vertex; i++)
		{
			graphData[i].resize(vertex);
		}

		for(auto i = 0; i < vertex; i++)
		{
			for(auto j=0; j<vertex; j++)
			{
				graphData[i][j] = 0;
			}
		}

		int temp = 0;

		while(true)
		{
			file >> line;
			if(line == "EDGE_WEIGHT_SECTION")
			{
				while(line != "EOF")
				{
					for (auto i = 0; i < vertex; i++)
					{
						file >> line;
						if (line != "EOF")
						{

							std::istringstream iss(line);
							iss >> graphData[temp][i];
							if(i == temp)
							{
								graphData[temp][i] = -1;
							}
						}
					}
					temp++;
				}
				break;
			}
		}
	}
	file.close();
}

void Graph::ReadFromFile(std::string filename)
{
	std::ifstream file;
	int temp = 0;

	//filename = filename + ".txt";

	file.open(filename);

	if (file.good())
	{
		file >> vertex;
		graphData.resize(vertex);

		for (auto i = 0; i < vertex; i++)
		{
			graphData[i].resize(vertex);
		}

		for (auto i = 0; i < vertex; i++)
		{
			for (auto j = 0; j < vertex; j++)
			{
				graphData[i][j] = -1;
			}
		}

		while (!file.eof())
		{
			for (auto i = 0; i < vertex; i++)
			{
				for (auto j = 0; j < vertex; j++)
				{
					file >> graphData[i][j];
				}
			}

		}
	}
	else
	{
		system("cls");
		std::cout << "Otworzenie pliku nie powiodlo sie" << std::endl;

	}
	file.close();
}
