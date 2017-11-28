#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrNext = nullptr;
	m_ptrPrev = nullptr;

    
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;

	m_itemCount = 0;



}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
   
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	if (m_itemCount == 0)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;

	}
	else
	{
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
	}
	m_itemCount++;


	
}

void LinkedList::PushBack( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	if (m_itemCount == 0)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;

	}
	else
	{
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
	}
	m_itemCount++;


}

void LinkedList::PopFront() noexcept
{
	if (m_itemCount == 1)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else if (m_itemCount > 1)
	{
		Node* ptrSecond = m_ptrFirst->m_ptrNext;
		ptrSecond->m_ptrPrev = nullptr;
		
		delete m_ptrFirst;

		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}

}

void LinkedList::PopBack() noexcept
{
	if (m_itemCount == 1)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else if (m_itemCount > 1)
	{
		Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
		ptrSecondToLast->m_ptrNext = nullptr;

		delete m_ptrLast;

		m_ptrLast = ptrSecondToLast;
		m_itemCount--;
	}
}




CustomerData LinkedList::GetFront()
{
	if (m_itemCount == 0)
	{
		throw out_of_range("list is empty!!");

	}
	else
	{
		return m_ptrFirst->m_data;
	}
}



CustomerData LinkedList::GetBack()

{
	if (m_itemCount == 0)
	{
		throw out_of_range("list is empty!!");

	}
	else
	{
		return m_ptrLast->m_data;
	}
}

CustomerData& LinkedList::operator[](const int index)
{
	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Data unvalid!");
	}


	int counter = 0;
	Node*ptrCurrent = m_ptrFirst;

	for (counter = 0; counter < index; counter++)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
	}
	return (ptrCurrent->m_data);



	
}

bool LinkedList::IsEmpty()
{
	if (m_itemCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::Size()
{
	return (m_itemCount);
}

