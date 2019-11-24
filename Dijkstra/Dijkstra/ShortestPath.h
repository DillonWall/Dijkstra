/*************************************************************
* Author: Dillon Wall
* Filename: ShortestPath.h
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#pragma once
#include <string>

/************************************************************************
* Class: Node
*
* Purpose: This class is a Node for a Linked List
*
* Manager functions:
* ShortestPath(int distance, float hours, std::string path);
*
* Methods:
* int GetDistance() const;
* float GetTimeHours() const;
* float GetTimeMinutes() const;
*		returns hours * 60
* std::string GetPathAsString() const;
*
*
*************************************************************************/
class ShortestPath
{
public:
	ShortestPath(int distance, float hours, std::string path);

	int GetDistance() const;
	float GetTimeHours() const;
	float GetTimeMinutes() const;
	std::string GetPathAsString() const;

private:
	int m_distance;
	float m_hours;
	std::string m_path;
};