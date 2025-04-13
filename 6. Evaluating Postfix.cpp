#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

/*Node Class*/
class Node{
	private:
		Node *nextNode;
		string object;
		
	public:
		string get()
		{
			return object;
		}
		void set(const string addObject)
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


/*Stack Class*/
class Stack{
	private:
		Node* head;
		int size;
		
	public:
		Stack()
		{
			head = new Node();
			head->setNext(NULL);
			size=0;
		}
		~Stack()
		{
			Node* temp=head->getNext();
			while(!isEmpty())
			{
				delete head;
				head=temp;
				temp=temp->getNext();
			}
			delete head;
		}
		
		string pop();
		void push(const string);
		int isEmpty();
};

/*pop method*/
string Stack::pop()
{
	if(isEmpty())
	{
		return NULL;
	}	
	string temp=head->get();
	Node* p=head;
	head=head->getNext();
	delete p;
	size--;
	return temp;
}

/*push method*/
void Stack::push(const string str)
{
	Node* newNode = new Node();
	newNode->set(str);
	newNode->setNext(head);
	head=newNode;
	size++;
}

/*isEmpty method*/
int Stack::isEmpty()
{
	return (head==NULL);
}

int main()
{
	char* arr[7]={"4","3","25","*","+", NULL};
	Stack s;
	
	char* element;
	string temp1;
	string temp2;
	int op1, op2, value;
	for(int i=0; arr[i]!=NULL; i++)
    {
       	element=arr[i];
    	if((element!="+") && (element!="*"))
    	{
    		s.push(element);
		}
		else
		{
			temp2=s.pop();
			temp1=s.pop();
			op2=stoi(temp2);
			op1=stoi(temp1);
			if(element=="*")
			{
				value=op1*op2;
				string strVal=to_string(value);
				s.push(strVal);
			}
			else if(element=="+")
			{
				value=op1+op2;
				string strVal=to_string(value);
				s.push(strVal);
			}
		}
	}
	const string finalResult=s.pop();
	cout<<"Final result is: "<<finalResult<<"\n";
}