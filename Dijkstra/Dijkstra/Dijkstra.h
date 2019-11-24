/*************************************************************
* Author: Dillon Wall
* Filename: Dijkstra.h
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "ShortestPath.h"
#include "Graph.h"

/************************************************************************
* Class: Dijkstra
*
* Purpose: This class executes the logic for Dijkstra's algorithm
*
* Manager functions:
* Dijkstra(std::string filename);
*
* Methods:
* ShortestPath GetShortestPath(std::string source, std::string destination);
*		executes Dijkstra's algorithm and puts the results into a ShortestPath object
* int GetListPosition(std::list<Vertex<std::string, std::string> *> verticies, Vertex<std::string, std::string> * vert) const;
*		private function to find what position in the list a certain vertex is
*
*
*************************************************************************/
class Dijkstra
{
public:
	Dijkstra(std::string filename);
	ShortestPath GetShortestPath(std::string source, std::string destination);
	
	static const int SPEED = 55;
	static const int I5_SPEED = 65;

private:
	int GetListPosition(std::list<Vertex<std::string, std::string> *> verticies, Vertex<std::string, std::string> * vert) const;

	Graph<std::string, std::string> m_graph;
};