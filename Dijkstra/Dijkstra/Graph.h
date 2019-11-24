/*************************************************************
* Author: Dillon Wall
* Filename: Graph.h
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#pragma once

#include <list>
#include "Vertex.h"
#include "Edge.h"
#include "Exception.h"
#include "Stack.h"
#include "Queue.h"

/************************************************************************
* Class: Graph
*
* Purpose: This class is a Graph data structure
*
* Manager functions:
* Graph();
* ~Graph();
* Graph(const Graph<V, E>& other);
* Graph<V, E>& operator=(const Graph<V, E>& rhs);
*
* Methods:
* int Size() const;
*		returns m_count
* bool IsEmpty() const;
*		returns true if there are no verticies
* std::list<Vertex<V, E> *> GetVerticies() const;
*		returns m_verticies
* void InsertVertex(V data);
*		adds a vertex
* void DeleteVertex(V data);
*		removes a vertex with the same data
* void InsertEdge(V from, V to, E edge, int weight);
*		adds an edge from one vertex to another
* void DeleteEdge(V from, V to);
*		deletes an edge from one vertex to another
* Edge<V, E> GetEdge(V from, V to);
*		returns an edge from one vertex to another
* void DepthFirst(void(*visit) (V data), V start);
*		performs the visit function with depth-first on each vertex starting at a vertex
* void BreadthFirst(void(*visit) (V data), V start);
*		performs the visit function with breadth-first on each vertex starting at a vertex
*
*************************************************************************/
template <typename V, typename E>
class Graph
{
public:
	Graph();
	~Graph();
	Graph(const Graph<V, E>& other);
	Graph<V, E>& operator=(const Graph<V, E>& rhs);

	int Size() const;
	bool IsEmpty() const;
	std::list<Vertex<V, E> *> GetVerticies() const;

	void InsertVertex(V data);
	void DeleteVertex(V data);
	void InsertEdge(V from, V to, E edge, int weight);
	void DeleteEdge(V from, V to);
	Edge<V, E> GetEdge(V from, V to);

	void DepthFirst(void(*visit) (V data), V start);
	void BreadthFirst(void(*visit) (V data), V start);

private:
	std::list<Vertex<V, E> *> m_verticies;
	int m_count;
};


template <typename V, typename E>
Graph<V, E>::Graph() : m_verticies(), m_count(0)
{
}

template <typename V, typename E>
Graph<V, E>::~Graph()
{
	for (Vertex<V, E> * v : m_verticies)
		delete v;

	m_verticies = std::list<Vertex<V, E> *>();
	m_count = 0;
}

template<typename V, typename E>
inline Graph<V, E>::Graph(const Graph<V, E> & other) : m_verticies(), m_count(other.m_count)
{
	for (Vertex<V, E> * v : other.m_verticies)
		m_verticies.push_back(new Vertex<V, E>(*v));
}

template<typename V, typename E>
inline Graph<V, E> & Graph<V, E>::operator=(const Graph<V, E> & rhs)
{
	if (this != &rhs)
	{
		for (Vertex<V, E> * v : m_verticies)
			delete v;

		for (Vertex<V, E> * v : rhs.m_verticies)
			m_verticies.push_back(new Vertex<V, E>(*v));
		m_count = rhs.m_count;
	}

	return *this;
}

template<typename V, typename E>
inline int Graph<V, E>::Size() const
{
	return m_count;
}

template<typename V, typename E>
inline bool Graph<V, E>::IsEmpty() const
{
	return m_count == 0;
}

template<typename V, typename E>
inline std::list<Vertex<V, E>*> Graph<V, E>::GetVerticies() const
{
	return m_verticies;
}

template<typename V, typename E>
inline void Graph<V, E>::InsertVertex(V data)
{
	bool alreadyInserted = false;
	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == data)
		{
			alreadyInserted = true;
		}
	}

	if (!alreadyInserted)
	{
		m_verticies.push_back(new Vertex<V, E>(data));
		++m_count;
	}
}

template<typename V, typename E>
inline void Graph<V, E>::DeleteVertex(V data)
{
	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == data)
		{
			m_verticies.remove(v);
			delete v;
			--m_count;
			return;
		}
	}

	throw Exception("Could not find vertex to delete");
}

template<typename V, typename E>
inline void Graph<V, E>::InsertEdge(V from, V to, E edge, int weight)
{
	Vertex<V, E> * fromV = nullptr;
	Vertex<V, E> * toV = nullptr;

	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == from)
			fromV = v;
		if (v->GetData() == to)
			toV = v;
	}

	if (fromV == nullptr)
		throw Exception("InsertEdge 'from' value not found in graph");
	if (toV == nullptr)
		throw Exception("InsertEdge 'to' value not found in graph");

	fromV->AddEdge(Edge<V, E>(edge, toV, weight));
	toV->ModIndegree(1);
}

template<typename V, typename E>
inline void Graph<V, E>::DeleteEdge(V from, V to)
{
	Vertex<V, E> * fromV = nullptr;
	Vertex<V, E> * toV = nullptr;

	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == from)
			fromV = v;
		if (v->GetData() == to)
			toV = v;
	}

	if (fromV == nullptr)
		throw Exception("DeleteEdge 'from' value not found in graph");
	if (toV == nullptr)
		throw Exception("DeleteEdge 'to' value not found in graph");

	fromV->RemoveEdge(toV);
	toV->ModIndegree(-1);
}

template<typename V, typename E>
inline Edge<V, E> Graph<V, E>::GetEdge(V from, V to)
{
	Vertex<V, E> * fromV = nullptr;
	Vertex<V, E> * toV = nullptr;

	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == from)
			fromV = v;
		if (v->GetData() == to)
			toV = v;
	}

	if (fromV == nullptr)
		throw Exception("GetEdge 'from' value not found in graph");
	if (toV == nullptr)
		throw Exception("GetEdge 'to' value not found in graph");

	return fromV->GetEdge(toV);
}

template<typename V, typename E>
inline void Graph<V, E>::DepthFirst(void(*visit)(V data), V start)
{
	Vertex<V, E> * startV = nullptr;

	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == start)
			startV = v;
	}

	if (startV == nullptr)
		throw Exception("DepthFirst 'start' value not found in graph");

	Stack<Vertex<V, E>*> stk;
	stk.Push(startV);
	startV->SetProcessed(true);

	while (!stk.isEmpty())
	{
		Vertex<V, E> * temp = stk.Pop();
		std::list<Edge<V, E>> edges = temp->GetEdges();

		for (Edge<V, E> e : edges)
		{
			if (!e.GetDestination()->GetProcessed())
			{
				stk.Push(e.GetDestination());
				e.GetDestination()->SetProcessed(true);
			}
		}

		visit(temp->GetData());
	}

	for (Vertex<V, E> * v : m_verticies)
		v->SetProcessed(false);
}

template<typename V, typename E>
inline void Graph<V, E>::BreadthFirst(void(*visit)(V data), V start)
{
	Vertex<V, E> * startV = nullptr;

	for (Vertex<V, E> * v : m_verticies)
	{
		if (v->GetData() == start)
			startV = v;
	}

	if (startV == nullptr)
		throw Exception("BreadthFirst 'start' value not found in graph");

	Queue<Vertex<V, E>*> que;
	que.Enqueue(startV);
	startV->SetProcessed(true);

	while (!que.isEmpty())
	{
		Vertex<V, E> * temp = que.Dequeue();
		std::list<Edge<V, E>> edges(temp->GetEdges());

		for (Edge<V, E> e : edges)
		{
			if (!e.GetDestination()->GetProcessed())
			{
				que.Enqueue(e.GetDestination());
				e.GetDestination()->SetProcessed(true);
			}
		}

		visit(temp->GetData());
	}

	for (Vertex<V, E> * v : m_verticies)
		v->SetProcessed(false);
}
