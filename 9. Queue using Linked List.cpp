#include <iostream>
#include <stdlib.h>
using namespace std;

/*Node Class*/
class Node{
	private:
		int object;
		Node *nextNode;
		
	public:
		int get()
		{
			return object;
		}
		void set(int addObject)
		{
			object=addObject;
		}
		
		Node* getNext()
		{
			return nextNode;
		}
		void setNext(Node* nextNode)
		{
			this->nextNode=nextNode;
		}
};

/*Queue Class*/
class Queue{
	private:
		Node* front;
		Node* rear;
		
	public:
		Queue()
		{
			front->setNext(NULL);
			rear=NULL;
			size=0;
		}
		~Queue()
		{
			Node* p=front;
			Node* temp;
			while(front!=NULL)
			{
				temp=front;
				front=front->getNext();
				delete temp;
			}
			delete p;
		}
		
		void enqueue(int x);
		int dequeue();
		int front();
		int isEmpty();
};

/*Insert an element in the rear*/
void Queue::enqueue(int x)
{
	if(rear!=NULL)
	{
		Node* newNode = new Node();
		newNode->set(x);
		newNode->setNext(NULL);
		rear->setNext(newNode);
		rear=newNode;
	}
	else
	{
		Node* newNode = new Node();
		newNode->set(x);
		newNode->setNext(NULL);
		rear->setNext(newNode);
		rear=newNode;
		front=newNode;
	}
}

/*Remove element from the front*/
int Queue::dequeue()
{
	int x=front->get();
	Node* p=front;
	front=front->getNext();
	delete p;
	return x;
}

/*To retrieve the front element*/
int Queue::front()
{
	return front->get();
}

/*To check if the queue is empty*/
int Queue::isEmpty()
{
	return (front==NULL);
}