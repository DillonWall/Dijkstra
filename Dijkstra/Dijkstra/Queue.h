/*************************************************************
* Author: Dillon Wall
* Filename: Queue.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/
#pragma once

#include "List.h"
#include "Exception.h"

/************************************************************************
* Class: Queue
*
* Purpose: This class represents a Queue data structure
*
* Manager functions:
* Queue();
* Queue(const Queue& copy);
* ~Queue();
* Queue& operator=(const Queue& rhs);
*
* Methods:
* void Enqueue(const T& item);
*		enqueues an item to the end of the queue
* T Dequeue();
*		dequeues an item from the front of the queue and returns it
* T& Front() const;
*		return a const reference to the data in the first element.
* int Size() const;
*		returns m_numElements
* bool isEmpty() const;
*		does the list have any elements in it ?
*
*
*************************************************************************/
template <typename T>
class Queue
{
public:
	Queue();
	Queue(const Queue& copy);
	~Queue();
	Queue& operator=(const Queue& rhs);

	void Enqueue(const T& item);
	T Dequeue();
	T& Front() const;
	int Size() const;
	bool isEmpty() const;

private:
	List<T>* m_list;
	int m_numElements;
};


template <typename T>
inline Queue<T>::Queue() : m_list(nullptr), m_numElements(0)
{
	m_list = new List<T>();
}

template<typename T>
inline Queue<T>::Queue(const Queue<T> & copy) : m_list(nullptr), m_numElements(copy.m_numElements)
{
	m_list = new List<T>(*(copy.m_list));
}


template <typename T>
inline Queue<T>::~Queue()
{
	delete m_list;
	m_numElements = 0;
}

template<typename T>
inline Queue<T> & Queue<T>::operator=(const Queue<T> & rhs)
{
	if (this != &rhs)
	{
		delete m_list;
		m_numElements = 0;

		m_list = new List<T>(*(rhs.m_list));
		m_numElements = rhs.m_numElements;
	}

	return *this;
}

template<typename T>
inline void Queue<T>::Enqueue(const T& item)
{
	m_list->Append(item);
	++m_numElements;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
	if (isEmpty())
		throw Exception("Queue Underflow");

	--m_numElements;
	T temp = m_list->First();
	m_list->Extract(temp);
	return temp;
}

template<typename T>
inline T& Queue<T>::Front() const
{
	if (isEmpty())
		throw Exception("Checking empty Queue");

	return m_list->First();
}

template<typename T>
inline int Queue<T>::Size() const
{
	return m_numElements;
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return Size() == 0;
}