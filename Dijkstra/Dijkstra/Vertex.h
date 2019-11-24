/*************************************************************
* Author: Dillon Wall
* Filename: Vertex.h
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#pragma once

#include <list>
#include "Edge.h"

/************************************************************************
* Class: Vertex
*
* Purpose: This class is a Vertex for a Graph
*
* Manager functions:
* Vertex();
* explicit Vertex(V data);
* ~Vertex();
* Vertex(const Vertex<V, E>& other);
* Vertex<V, E>& operator=(const Vertex<V, E>& rhs);
* bool operator==(const Vertex<V, E>& rhs) const;
* bool operator!=(const Vertex<V, E>& rhs) const;
*
* Methods:
* V& GetData();
* V GetData() const;
* void SetData(V data);
* bool GetProcessed() const;
* void SetProcessed(bool processed);
* void AddEdge(Edge<V, E> e);
*		adds an edge to m_edges
* void RemoveEdge(Vertex<V, E> * destination);
*		removes an edge from m_edges that has a specific destination
* Edge<V, E> GetEdge(Vertex<V, E> * destination) const;
*		returns an edge from m_edges that has a specific destination
* std::list<Edge<V, E>> GetEdges();
*		returns m_edges
* void ModIndegree(int amt);
*		adds amt to m_indegree
*
*
*************************************************************************/
template <typename V, typename E>
class Vertex
{
public:
	Vertex();
	explicit Vertex(V data);
	~Vertex();
	Vertex(const Vertex<V, E>& other);
	Vertex<V, E>& operator=(const Vertex<V, E>& rhs);

	bool operator==(const Vertex<V, E>& rhs) const;
	bool operator!=(const Vertex<V, E>& rhs) const;

	V& GetData();
	V GetData() const;
	void SetData(V data);
	bool GetProcessed() const;
	void SetProcessed(bool processed);
	void AddEdge(Edge<V, E> e);
	void RemoveEdge(Vertex<V, E> * destination);
	Edge<V, E> GetEdge(Vertex<V, E> * destination) const;
	std::list<Edge<V, E>> GetEdges();
	void ModIndegree(int amt);

private:
	V m_data;
	std::list<Edge<V, E>> m_edges;
	int m_indegree;
	int m_outdegree;
	bool m_processed;
};


template <typename V, typename E>
Vertex<V, E>::Vertex() : m_data(), m_edges(), m_indegree(0), m_outdegree(0), m_processed(false)
{
}

template<typename V, typename E>
inline Vertex<V, E>::Vertex(V data) : m_data(data), m_edges(), m_indegree(0), m_outdegree(0), m_processed(false)
{
}

template <typename V, typename E>
Vertex<V, E>::~Vertex()
{
	m_data = V();
	m_edges = std::list<Edge<V, E>>();
	m_indegree = 0;
	m_outdegree = 0;
	m_processed = false;
}

template<typename V, typename E>
inline Vertex<V, E>::Vertex(const Vertex<V, E>& other) : m_data(other.m_data), m_edges(other.m_edges), m_indegree(other.m_indegree), m_outdegree(other.m_outdegree), m_processed(other.m_processed)
{
}

template<typename V, typename E>
inline Vertex<V, E>& Vertex<V, E>::operator=(const Vertex<V, E>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_edges = rhs.m_edges;
		m_indegree = rhs.m_indegree;
		m_outdegree = rhs.m_outdegree;
		m_processed = rhs.m_processed;
	}

	return *this;
}

template<typename V, typename E>
inline bool Vertex<V, E>::operator==(const Vertex<V, E>& rhs) const
{
	return m_data == rhs.m_data;
}

template<typename V, typename E>
inline bool Vertex<V, E>::operator!=(const Vertex<V, E>& rhs) const
{
	return m_data != rhs.m_data;
}

template<typename V, typename E>
inline V & Vertex<V, E>::GetData()
{
	return m_data;
}

template<typename V, typename E>
inline V Vertex<V, E>::GetData() const
{
	return m_data;
}

template<typename V, typename E>
inline void Vertex<V, E>::SetData(V data)
{
	m_data = data;
}

template<typename V, typename E>
inline bool Vertex<V, E>::GetProcessed() const
{
	return m_processed;
}

template<typename V, typename E>
inline void Vertex<V, E>::SetProcessed(bool processed)
{
	m_processed = processed;
}

template<typename V, typename E>
inline void Vertex<V, E>::AddEdge(Edge<V, E> e)
{
	m_edges.push_back(e);
	++m_outdegree;
}

template<typename V, typename E>
inline void Vertex<V, E>::RemoveEdge(Vertex<V, E> * destination)
{
	for (Edge<V, E> e : m_edges)
	{
		if (e.GetDestination() == destination)
		{
			m_edges.remove(e);
			--m_outdegree;
			return;
		}
	}
}

template<typename V, typename E>
inline Edge<V, E> Vertex<V, E>::GetEdge(Vertex<V, E>* destination) const
{
	for (Edge<V, E> e : m_edges)
	{
		if (e.GetDestination() == destination)
		{
			return e;
		}
	}
}

template<typename V, typename E>
inline std::list<Edge<V, E>> Vertex<V, E>::GetEdges()
{
	return m_edges;
}

template<typename V, typename E>
inline void Vertex<V, E>::ModIndegree(int amt)
{
	m_indegree += amt;
}
