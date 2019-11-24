/*************************************************************
* Author: Dillon Wall
* Filename: Node.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/
#pragma once

template <typename T>
class List;

/************************************************************************
* Class: Node
*
* Purpose: This class is a Node for a Linked List
*
* Manager functions:
* Node();
* Node(T data);
* Node(const Node<T>& copy);
* Node<T>& operator=(const Node<T>& rhs);
* ~Node();
*
* Methods:
* const T& GetData() const;
*		returns the data of the node
* void SetData(T data);
*		sets the data
* Node<T>* GetNext() const;
*		gets a pointer to the next node
* void SetNext(Node<T>* next);
*		set the pointer to the next node
* Node<T>* GetPrevious() const;
*		gets a pointer to the previous node
* void SetPrevious(Node<T>* previous);
*		sets a pointers to the previous node
*
*
*************************************************************************/
template <typename T>
class Node
{
	friend class List<T>;

public:
	
	T& GetData();
	void SetData(T data);
	Node<T>* GetNext() const;
	void SetNext(Node<T>* next);
	Node<T>* GetPrevious() const;
	void SetPrevious(Node<T>* previous);

private:
	T m_data;
	Node<T>* m_next;
	Node<T>* m_previous;

	Node();
	Node(T data);
	Node(const Node<T>& copy);
	Node<T>& operator=(const Node<T>& rhs);
	~Node();
};


/// Function Code ///

template<typename T>
inline T& Node<T>::GetData()
{
	return m_data;
}

template<typename T>
inline void Node<T>::SetData(T data)
{
	m_data = data;
}

template<typename T>
inline Node<T> * Node<T>::GetNext() const
{
	return m_next;
}

template<typename T>
inline void Node<T>::SetNext(Node<T>* next)
{
	m_next = next;
}

template<typename T>
inline Node<T>* Node<T>::GetPrevious() const
{
	return m_previous;
}

template<typename T>
inline void Node<T>::SetPrevious(Node<T>* previous)
{
	m_previous = previous;
}



template<typename T>
inline Node<T>::Node() : m_data(T()), m_next(nullptr), m_previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(T data) : m_data(data), m_next(nullptr), m_previous(nullptr)
{
}

template<typename T>
inline Node<T>::Node(const Node<T>& copy) : m_data(copy.m_data), m_next(nullptr), m_previous(nullptr)
{	
}

template<typename T>
inline Node<T>& Node<T>::operator=(const Node<T>& rhs)
{
	if (this != &rhs)
	{
		//nothing to delete

		m_data = rhs.m_data;
		m_next = nullptr;
		m_previous = nullptr;
	}

	return *this;
}

template<typename T>
inline Node<T>::~Node()
{
	//No deletes

	//Default values
	m_data = T();
	m_next = nullptr;
	m_previous = nullptr;
}
