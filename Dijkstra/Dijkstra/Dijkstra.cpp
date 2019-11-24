/*************************************************************
* Author: Dillon Wall
* Filename: Dijkstra.cpp
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#include "Dijkstra.h"

Dijkstra::Dijkstra(std::string filename) : m_graph()
{
	std::string line;
	std::ifstream file(filename);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::vector<std::string> strings;
			std::istringstream ssLine(line);
			std::string s;
			while (std::getline(ssLine, s, ','))
			{
				strings.push_back(s);
			}

			if (strings.size() < 4)
				throw Exception("Invalid file input");

			m_graph.InsertVertex(strings.at(0));
			m_graph.InsertVertex(strings.at(1));
			m_graph.InsertEdge(strings.at(0), strings.at(1), strings.at(2), atoi(strings.at(3).c_str()));
			m_graph.InsertEdge(strings.at(1), strings.at(0), strings.at(2), atoi(strings.at(3).c_str()));
		}
		file.close();
	}
	else
		throw Exception("Unable to open file!");
}

ShortestPath Dijkstra::GetShortestPath(std::string start, std::string destination)
{
	int size = m_graph.Size();
	std::list<Vertex<std::string, std::string> *> verts = m_graph.GetVerticies();
	Vertex<std::string, std::string>* current;

	//Create and init distance and predecessor arrays
	int * distance = new int[size];
	int * predecessor = new int[size];
	for (int i = 0; i < size; ++i)
	{
		distance[i] = -1;
		predecessor[i] = -1;
	}

	//Find starting vertex
	int startPos = 0;
	for (Vertex<std::string, std::string> * v : verts)
	{
		if (v->GetData() != start)
			++startPos;
		else
		{
			current = v;
			break;
		}
	}

	if (startPos == size)
		throw Exception("GetShortestPath 'start' value not found in graph");

	//Find destination vertex
	int destPos = 0;
	for (Vertex<std::string, std::string> * v : verts)
	{
		if (v->GetData() != destination)
			++destPos;
		else
			break;
	}

	if (destPos == size)
		throw Exception("GetShortestPath 'destination' value not found in graph");

	//Do dijkstra algorithm
	distance[startPos] = 0;
	while (current != nullptr)
	{
		int curPos = GetListPosition(verts, current);
		int distFromStart = distance[curPos];

		for (Edge<std::string, std::string> e : current->GetEdges())
		{
			if (!e.GetDestination()->GetProcessed())
			{
				int pos = GetListPosition(verts, e.GetDestination());
				int length = e.GetWeight();

				if (distance[pos] == -1 || distFromStart + length < distance[pos])
				{
					predecessor[pos] = curPos;
					distance[pos] = distFromStart + length;
				}
			}
		}

		current->SetProcessed(true);

		current = nullptr;
		int shortest = -1;
		int i = 0;
		for (Vertex<std::string, std::string> * v : verts)
		{
			if (!v->GetProcessed() && distance[i] != -1 && (shortest == -1 || distance[i] < shortest))
			{
				current = v;
				shortest = distance[i];
			}
			++i;
		}
	}

	//reset processed
	for (Vertex<std::string, std::string> * v : verts)
		v->SetProcessed(false);

	//get vector of vertex for path and calc values
	std::string pathList = "";
	std::string prevStr = "";
	float hours = 0.0f;
	int i = destPos;
	Vertex<std::string, std::string> * cur = nullptr;
	Vertex<std::string, std::string> * next = nullptr;
	int j = 0;
	for (Vertex<std::string, std::string> * v : verts)
	{
		if (j == destPos)
		{
			cur = v;
			break;
		}
		++j;
	}
	while (predecessor[i] != -1)
	{		
		j = 0;
		for (Vertex<std::string, std::string> * v : verts)
		{
			if (j == predecessor[i])
			{
				next = v;
				break;
			}
			++j;
		}

		Edge<std::string, std::string> edge = m_graph.GetEdge(next->GetData(), cur->GetData());
		if (edge.GetData() != prevStr)
		{
			pathList.insert(0, edge.GetData() + ((i != destPos) ? ", " : ""));
			prevStr = edge.GetData();
		}
		if (edge.GetData() == "I-5")
			hours += edge.GetWeight() / float(I5_SPEED);
		else
			hours += edge.GetWeight() / float(SPEED);

		i = predecessor[i];
		cur = next;
	}

	if (distance[destPos] < 0) 
		throw Exception("Could not find path to destination");

	ShortestPath path(distance[destPos], hours, pathList);
	delete distance;
	delete predecessor;

	return path;
}

int Dijkstra::GetListPosition(std::list<Vertex<std::string, std::string>*> verticies, Vertex<std::string, std::string>* vert) const
{
	int pos = 0;
	for (Vertex<std::string, std::string> * v : verticies)
	{
		if (v == vert)
			return pos;
		else
			++pos;
	}

	throw Exception("GetShortestPath 'start' value not found in graph");
}
