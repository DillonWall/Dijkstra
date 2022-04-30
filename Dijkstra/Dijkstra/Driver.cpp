/*************************************************************
*
* Lab / Assignment: Lab5 - Dijkstra
*
* Overview:
*		This program is an implementation of Dijkstra's
*		algorithm. The user will specify a source file of
*		roads and what locations they connect, and request
*		the shortest path between two locations which the
*		program calculates using a Graph and Dijkstra's 
*		algorithm. The program also outputs some useful
*		information about the distance, time, and road path.
*
* Input:
*		The program prompts for filename of the source file, if the
*		user inputs 'd' then a default file will be used (lab04.txt).
*		Then the user is prompted for the name of a start location
*		and then an end location. After outputing results, the user
*		is prompted if they would like to continue. If 'y' is input,
*		then the program will start over from asking the start and 
*		end locations.
*
* Output:
*		The program will prompt the user for filename, then start
*		location, then end location. After calculating, the program
*		outputs the shortest distance between the locations, the
*		time it will take in hours and then in minutes, and also
*		the route one should take for this shortest path. The user
*		is then promted to continue and starts over from the 
*		start location prompt.
*
**************************************************************/

/*************************************************************
* Author: Dillon Wall
* Filename: Driver.cpp
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#define _CRTDBG_MAP_ALLOC

#include "Dijkstra.h"
#include "Exception.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

static const std::string DEFAULT_FILE = "lab04.txt";
//static const char * DEFAULT_FILE = "lab04.txt";

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::string filename = "";
	//char filename[100];
	cout << "Enter your source file name ('d' for default file): ";
	std::getline(cin, filename);
	//if (strcmp(filename, "d") == 0)
	//	strcpy(filename, DEFAULT_FILE);
	if (filename == "d")
		filename = DEFAULT_FILE;

	try
	{
		Dijkstra dijkstra(filename);

		bool shouldQuit = false;
		while (!shouldQuit)
		{
			//get input
			std::string start;
			cout << "Enter Start: ";
			std::getline(cin, start);
			std::string destination;
			cout << "Enter Destination: ";
			std::getline(cin, destination);

			ShortestPath path = dijkstra.GetShortestPath(start, destination);
			cout << "Traveling from " << start << " to " << destination << " will be a distance of " << path.GetDistance() << " miles." << endl;
			cout << "It will take at least " << path.GetTimeHours() << " hours, or " << path.GetTimeMinutes() << " minutes." << endl;
			cout << "Route from " << start << " to " << destination << ": " << endl;
			cout << path.GetPathAsString() << endl;

			//check if should continue
			std::string cont;
			cout << "Continue? (y/n): ";
			std::getline(cin, cont);
			if (cont != "y")
				shouldQuit = true;

			//spacing
			cout << endl << endl;
		}
	}
	catch (Exception e)
	{
		cout << e.GetMsg() << endl;
		cout << "Exiting..." << endl;
		exit(1);
	}

	return 0;
}