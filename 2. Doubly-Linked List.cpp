#include <iostream>
#include <stdlib.h>
using namespace std;

/*Node class*/
class Node{
	private:
		int object;
		Node* nextNode;
		Node* prevNode;
		
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
		
		Node* getPrev()
		{
			return prevNode;
		}
		void setPrev(Node* prevNode)
		{
			this->prevNode=prevNode;
		}
};

/*List class*/
class List{
	private:
		Node* headNode;
		Node* currentNode;
		int size;
		
	public:
		/*Constructor*/
		List()
		{
			headNode = new Node();
			headNode->setNext(NULL);
			currentNode=NULL;
			size=0;
		}
		/*Destructor*/
		~List()
		{
			Node* currentNode=headNode->getNext();
			Node* tmpNode;
			while(currentNode!=NULL)
			{
				tmpNode=currentNode->getNext();
				delete currentNode;
				currentNode=tmpNode;
			}
			delete headNode;
		}
		
		void add(int addObject);
		void remove();
		bool next();
		int get();
		friend void traverse(List list);
		void start();
		int length();
		friend List addNodes();
};

/*add function*/
void List::add(int addObject)
{
	Node* newNode = new Node();
	newNode->set(addObject);
	if(currentNode!=NULL)
	{
		newNode->setNext(currentNode->getNext());
		newNode->setPrev(currentNode);
		currentNode->setNext(newNode);
		currentNode=newNode;
	}
	else
	{
		newNode->setNext(NULL);
		newNode->setPrev(headNode);
		headNode->setNext(newNode);
		headNode->setPrev(NULL);
		currentNode=newNode;
	}
	size++;
}

/*remove function*/
void List::remove()
{
	if(currentNode!=NULL && currentNode!=headNode)
	{
		(currentNode->getPrev())->setNext(currentNode->getNext());
		(currentNode->getNext())->setPrev(currentNode->getPrev());
		Node* tmpNode=currentNode->getNext();
		delete currentNode;
		currentNode=tmpNode;
		size--;
	}
}

/*next function*/
bool List::next()
{
	if(currentNode!=NULL)
	{
		currentNode=currentNode->getNext();
	}
	else
	{
		return false;
	}
	if(currentNode==NULL || size==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*get function*/
int List::get()
{
	if(currentNode!=NULL)
	{
		return currentNode->get();
	}
	else 
	{
	    return -1;
	}
}

/*traverse function*/
void traverse(List list)
{
	Node* savedCurrentNode=list.currentNode;
	list.currentNode=list.headNode;
	for(int i=0; list.next(); i++)
	{
		cout<<"Element at "<<i<<": "<<list.get()<<"\n";
	}
	list.currentNode=savedCurrentNode;
}

/*start function*/
void List::start()
{
	currentNode=headNode;
}

/*length function*/
int List::length()
{
	return size;
}

/*addNodes function*/
List addNodes()
{
	List list;
	list.add(2);
	list.add(6);
	list.add(8);
	list.add(7);
	list.add(1);
	cout<<"\nList size = "<<list.length()<<"\n";
	return list;
}

/*Here is the main function*/
int main()
{
	List list;
	list.add(5);
	list.add(13);
	list.add(4);
	list.add(8);
	list.add(24);
	list.add(48);
	list.add(12);
	
	list.start();
	while(list.next())
	{
		cout<<"List Element: "<<list.get()<<"\n";
	}

	List list2 = addNodes();
	
	traverse(list2);
}