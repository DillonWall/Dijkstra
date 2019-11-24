/*************************************************************
* Author: Dillon Wall
* Filename: ShortestPath.cpp
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#include "ShortestPath.h"

ShortestPath::ShortestPath(int distance, float hours, std::string path) : m_distance(distance), m_hours(hours), m_path(path)
{
}

int ShortestPath::GetDistance() const
{
	return m_distance;
}

float ShortestPath::GetTimeHours() const
{
	return m_hours;
}

float ShortestPath::GetTimeMinutes() const
{
	return m_hours * 60.0f;
}

std::string ShortestPath::GetPathAsString() const
{
	return m_path;
}
