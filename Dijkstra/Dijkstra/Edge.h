/*************************************************************
* Author: Dillon Wall
* Filename: Edge.h
* Date Created: 3/11/2019
* Modifications:
**************************************************************/
#pragma once

template <typename V, typename E>
class Vertex;

/************************************************************************
* Class: Edge
*
* Purpose: This class is an Edge for a Graph
*
* Manager functions:
* Edge();
* explicit Edge(E data);
* Edge(E data, Vertex<V, E> * destination);
* Edge(E data, Vertex<V, E> * destination, int weight);
* ~Edge();
* Edge(const Edge<V, E>& other);
* Edge<V, E>& operator=(const Edge<V, E>& rhs);
* bool operator==(const Edge<V, E>& rhs);
*
* Methods:
* E& GetData();
* E GetData() const;
* void SetData(E data);
* Vertex<V, E> * GetDestination() const;
* void SetDestination(Vertex<V, E> * destination);
* int GetWeight() const;
* void SetWeight(int weight);
*
*
*************************************************************************/
template <typename V, typename E>
class Edge
{
public:
	Edge();
	explicit Edge(E data);
	Edge(E data, Vertex<V, E> * destination);
	Edge(E data, Vertex<V, E> * destination, int weight);
	~Edge();
	Edge(const Edge<V, E>& other);
	Edge<V, E>& operator=(const Edge<V, E>& rhs);

	bool operator==(const Edge<V, E>& rhs);

	E& GetData();
	E GetData() const;
	void SetData(E data);
	Vertex<V, E> * GetDestination() const;
	void SetDestination(Vertex<V, E> * destination);
	int GetWeight() const;
	void SetWeight(int weight);

private:
	E m_data;
	Vertex<V, E> * m_destination;
	int m_weight;
};


template <typename V, typename E>
Edge<V, E>::Edge() : m_data(), m_destination(nullptr), m_weight(0)
{
}

template<typename V, typename E>
inline Edge<V, E>::Edge(E data) : m_data(data), m_destination(nullptr), m_weight(0)
{
}

template<typename V, typename E>
inline Edge<V, E>::Edge(E data, Vertex<V, E> * destination) : m_data(data), m_destination(destination), m_weight(0)
{
}

template<typename V, typename E>
inline Edge<V, E>::Edge(E data, Vertex<V, E>* destination, int weight) : m_data(data), m_destination(destination), m_weight(weight)
{
}

template <typename V, typename E>
Edge<V, E>::~Edge()
{
	m_data = E();
	m_destination = nullptr;
	m_weight = 0;
}

template<typename V, typename E>
inline Edge<V, E>::Edge(const Edge<V, E>& other) : m_data(other.m_data), m_destination(other.m_destination), m_weight(other.m_weight)
{
}

template<typename V, typename E>
inline Edge<V, E>& Edge<V, E>::operator=(const Edge<V, E>& rhs)
{
	if (this != &rhs)
	{
		m_data = rhs.m_data;
		m_destination = rhs.m_destination;
		m_weight = rhs.m_weight;
	}

	return *this;
}

template<typename V, typename E>
inline bool Edge<V, E>::operator==(const Edge<V, E>& rhs)
{
	return m_data == rhs.m_data;
}

template<typename V, typename E>
inline E & Edge<V, E>::GetData()
{
	return m_data;
}

template<typename V, typename E>
inline E Edge<V, E>::GetData() const
{
	return m_data;
}

template<typename V, typename E>
inline void Edge<V, E>::SetData(E data)
{
	m_data = data;
}

template<typename V, typename E>
inline Vertex<V, E> * Edge<V, E>::GetDestination() const
{
	return m_destination;
}

template<typename V, typename E>
inline void Edge<V, E>::SetDestination(Vertex<V, E>* destination)
{
	m_destination = destination;
}

template<typename V, typename E>
inline int Edge<V, E>::GetWeight() const
{
	return m_weight;
}

template<typename V, typename E>
inline void Edge<V, E>::SetWeight(int weight)
{
	m_weight = weight;
}
