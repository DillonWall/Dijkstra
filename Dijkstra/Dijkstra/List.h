/*************************************************************
* Author: Dillon Wall
* Filename: List.h
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#pragma once

#define DEBUG true

#include <iostream>
#include "Node.h"
#include "Exception.h"

/************************************************************************
* Class: List
*
* Purpose: This class is a Linked List
*
* Manager functions:
* List();
* List(const List<T>& copy);
* ~List();
* List<T>& operator=(const List<T>& rhs);
*
* Methods:
* bool IsEmpty() const;
*		does the list have any elements in it ?
* const T& First() const;
*		return a const reference to the data in the first element.
* const T& Last() const;
*		return a const reference to the data in the last element.
* void Prepend(const T& item);
*		add an item to the front of the list.
* void Append(const T& item);
*		add an item to the end of the list.
* void Purge();
*		remove all items from the list.
* void Extract(const T& item);
*		remove a single item from the list.
* void InsertAfter(const T& new_item, const T& existing_item);
*		insert an item after an item in the list.InsertAfter(new_item, existing_item);
* void InsertBefore(const T& new_item, const T& existing_item);
*		insert an item before an item in the list.InsertBefore(new_item, existing_item);
*
* Node<T>* GetHead() const;
*		return the head pointer(TESTING ONLY)
* Node<T>* GetTail() const;
*		return the tail pointer(TESTING ONLY)
* void PrintForwards() const;
* 	print the list forwards(TESTING ONLY)
* void PrintBackwards() const;
*		print the list backwards(TESTING ONLY)
*
*************************************************************************/
template <typename T>
class List
{
public:
	List();
	List(const List<T>& copy);
	~List();
	List<T>& operator=(const List<T>& rhs);

	bool IsEmpty() const;//isEmpty – does the list have any elements in it ?
	T& First() const;//First – return a const reference to the data in the first element.
	const T& Last() const;//Last – return a const reference to the data in the last element.
	void Prepend(const T& item);//Prepend – add an item to the front of the list.
	void Append(const T& item);//Append – add an item to the end of the list.
	void Purge();//Purge – remove all items from the list.
	void Extract(const T& item);//Extract – remove a single item from the list.
	void InsertAfter(const T& new_item, const T& existing_item);//InsertAfter – insert an item after an item in the list.InsertAfter(new_item, existing_item);
	void InsertBefore(const T& new_item, const T& existing_item);//InsertBefore – insert an item before an item in the list.InsertBefore(new_item, existing_item);

#if DEBUG==true
	Node<T>* GetHead() const;//getHead – return the head pointer(TESTING ONLY)
	Node<T>* GetTail() const;//getTail – return the tail pointer(TESTING ONLY)
	void PrintForwards() const;//PrintForwards – print the list forwards(TESTING ONLY)
	void PrintBackwards() const;//PrintBackwards – print the list backwards(TESTING ONLY)
#endif

private:
	Node<T>* m_head;
	Node<T>* m_tail;
};

template<typename T>
inline List<T>::List() : m_head(nullptr), m_tail(nullptr)
{
}

template<typename T>
inline List<T>::List(const List<T> & copy) : m_head(nullptr), m_tail(nullptr)
{
	if (copy.m_head != nullptr)
	{
		Node<T>* travel = copy.m_head;
		m_head = new Node<T>(*copy.m_head);
		m_tail = m_head;

		while (travel->GetNext() != nullptr)
		{
			//create new node as a deep copy and set m_tail's next and the next node's previous, then set m_tail to the next node
			Node<T>* temp = new Node<T>(*travel->GetNext());
			m_tail->SetNext(temp);
			temp->SetPrevious(m_tail);
			m_tail = temp;

			//iterate to next
			travel = travel->GetNext();
		}
	}
}

template<typename T>
inline List<T>::~List()
{
	Purge();

	//Default values
	m_head = nullptr;
	m_tail = nullptr;
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T> & rhs)
{
	if (this != &rhs)
	{
		Purge();

		//copy
		if (rhs.m_head != nullptr)
		{
			Node<T>* travel = rhs.m_head;
			m_head = new Node<T>(*rhs.m_head);
			m_tail = m_head;

			while (travel->GetNext() != nullptr)
			{
				//create new node as a deep copy and set m_tail's next and the next node's previous, then set m_tail to the next node
				Node<T>* temp = new Node<T>(*travel->GetNext());
				m_tail->SetNext(temp);
				temp->SetPrevious(m_tail);
				m_tail = temp;

				//iterate to next
				travel = travel->GetNext();
			}
		}
	}

	return *this;
}

#if DEBUG==true
template<typename T>
inline Node<T>* List<T>::GetHead() const
{
	return m_head;
}

template<typename T>
inline Node<T>* List<T>::GetTail() const
{
	return m_tail;
}

template<typename T>
inline void List<T>::PrintForwards() const
{
	Node<T>* travel = m_head;

	while (travel != nullptr)
	{
		std::cout << travel->GetData() << std::endl;

		//iterate to next
		travel = travel->GetNext();
	}
}

template<typename T>
inline void List<T>::PrintBackwards() const
{
	Node<T>* travel = m_tail;

	while (travel != nullptr)
	{
		std::cout << travel->GetData() << std::endl;

		//iterate to next
		travel = travel->GetPrevious();
	}
}
#endif

template<typename T>
inline bool List<T>::IsEmpty() const
{
	return (m_head == nullptr) ? true : false; //dont need to check tail since both will either have or not have data to point to
}

template<typename T>
inline T & List<T>::First() const
{
	return m_head->GetData();
}

template<typename T>
inline const T & List<T>::Last() const
{
	return m_tail->GetData();
}

template<typename T>
inline void List<T>::Prepend(const T & item)
{
	Node<T>* nn = new Node<T>(item);

	if (m_head != nullptr)
	{
		nn->SetNext(m_head);
		m_head->SetPrevious(nn);
	}
	else m_tail = nn;

	m_head = nn;
}

template<typename T>
inline void List<T>::Append(const T & item)
{
	Node<T>* nn = new Node<T>(item);

	if (m_tail != nullptr)
	{
		nn->SetPrevious(m_tail);
		m_tail->SetNext(nn);
	}
	else m_head = nn;

	m_tail = nn;
}

template<typename T>
inline void List<T>::Purge()
{
	Node<T>* travel = m_head;

	while (travel != nullptr)
	{
		travel = travel->GetNext();
		delete m_head;
		m_head = travel;
	}

	m_tail = nullptr;
}

template<typename T>
inline void List<T>::Extract(const T & item)
{
	if (m_head != nullptr)
	{
		Node<T>* travel = m_head;

		while (travel != nullptr && travel->GetData() != item)
		{
			travel = travel->GetNext();
		}

		if (travel != nullptr)
		{
			if (travel->GetPrevious() == nullptr && travel->GetNext() == nullptr) //only item
			{
				m_head = nullptr;
				m_tail = nullptr;
			}
			else
			{
				if (travel->GetPrevious() != nullptr) travel->GetPrevious()->SetNext(travel->GetNext());
				else m_head = travel->GetNext();
				if (travel->GetNext() != nullptr) travel->GetNext()->SetPrevious(travel->GetPrevious());
				else m_tail = travel->GetPrevious();
			}

			delete travel;
		}
		else
		{
			throw Exception("Extract item not found.");
		}
	}
	else
	{
		throw Exception("Empty list, cannot extract.");
	}
}

template<typename T>
inline void List<T>::InsertAfter(const T & new_item, const T & existing_item)
{
	Node<T>* travel = m_head;

	while (travel != nullptr && travel->GetData() != existing_item)
	{
		travel = travel->GetNext();
	}

	if (travel != nullptr)
	{
		Node<T>* nn = new Node<T>(new_item);

		nn->SetPrevious(travel);
		if (travel == m_tail) m_tail = nn;
		else
		{
			nn->SetNext(travel->GetNext());
			travel->GetNext()->SetPrevious(nn);
		}
		travel->SetNext(nn);
	}
	else
	{
		throw Exception("InsertAfter item not found.");
	}
}

template<typename T>
inline void List<T>::InsertBefore(const T & new_item, const T & existing_item)
{
	Node<T>* travel = m_head;

	while (travel != nullptr && travel->GetData() != existing_item)
	{
		travel = travel->GetNext();
	}

	if (travel != nullptr)
	{
		Node<T>* nn = new Node<T>(new_item);

		nn->SetNext(travel);
		if (travel == m_head) m_head = nn;
		else
		{
			nn->SetPrevious(travel->GetPrevious());
			travel->GetPrevious()->SetNext(nn);
		}
		travel->SetPrevious(nn);
	}
	else
	{
		throw Exception("InsertBefore item not found.");
	}
}
