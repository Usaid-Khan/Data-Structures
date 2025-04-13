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

/*List Class*/
class List{
	private:
		Node* headNode;
		Node* currentNode;
		Node* lastCurrentNode;
		int size;
		
	public:
		/*Constructor*/
		List()
		{
			headNode = new Node();
			headNode->setNext(NULL);
			currentNode=NULL;
			lastCurrentNode=NULL;
			size=0;
		}
		/*Destructor*/
		~List()
		{
			Node* currentNode=headNode->getNext();
			Node* newNode;
			while(currentNode!=NULL)
			{
				newNode=currentNode->getNext();
				delete currentNode;
				currentNode=newNode;
			}
			delete headNode;
		}
		
		/*Other member functions*/
		void add(int addObject);
		friend List addNodes();
		int get();
		bool next();
		friend void traverse(List list);
		void start();
		int length();
		void remove();
};

/*add function*/
void List::add(int addObject)
{
	Node* newNode = new Node();
	newNode->set(addObject);
	if(currentNode!=NULL)
	{
		newNode->setNext(currentNode->getNext());
		currentNode->setNext(newNode);
		lastCurrentNode=currentNode;
		currentNode=newNode;
	}
	else
	{
		newNode->setNext(NULL);
		headNode->setNext(newNode);
		lastCurrentNode=headNode;
		currentNode=newNode;
	}
	size++;
}

/*length function*/
int List::length()
{
	return size;
}

/*addNodes friend function*/
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

/*get function*/
int List::get()
{
	if(currentNode!=NULL)
	{
		return currentNode->get();
	}
}

/*next function*/
bool List::next()
{
	if(currentNode!=NULL)
	{
		lastCurrentNode=currentNode;
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

/*traverse function*/
void traverse(List list)
{
	Node* savedCurrentNode=list.currentNode;
	list.currentNode=list.headNode;
	for(int i=1; list.next(); i++)
	{
		cout<<"Element at "<<i<<": "<<list.get()<<"\n";
	}
	list.currentNode=savedCurrentNode;
}

/*start function*/
void List::start()
{
	currentNode=headNode;
	lastCurrentNode=headNode;
}

/*remove function*/
void List::remove()
{
	if(currentNode!=NULL  && currentNode!=headNode)
	{
	    lastCurrentNode->setNext(currentNode->getNext());
	    delete currentNode;
	    currentNode=lastCurrentNode->getNext();
	    size--;
	}
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