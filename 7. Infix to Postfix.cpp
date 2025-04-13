#include <iostream>
#include <cstring>
#include <string.h>
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
		string top();
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

/*top method*/
string Stack::top()
{
	return head->get();
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

/*prcd function*/
bool prcd(string op1, string op2)
{
	if((op1=="*") && (op2=="+"))
	{
		return true;
	}
	else if((op1=="+") && (op2=="+"))
	{
		return true;
	}
	else if((op1=="+") && (op2=="*"))
	{
		return false;
	}
	else if((op1=="(") && ((op2=="+") || (op2=="*")))
	{
		return false;
	}
	else if(((op1=="*") || (op1=="+")) && (op2==")"))
	{
		return false;
	}
	else if(((op1=="*") || (op1=="+")) && (op2=="("))
	{
		return true;
	}
	else if((op1==")") && ((op2=="*") || (op2=="+")))
	{
		return false;
	}
	else
	{
	    return -1;
	}
}

int main()
{
	int size=8, countPostfix=0, countStack=0;
	string op;
	char* arr[size]={"(","4","+","3",")","*","2", NULL};
	string postfix[size];
	Stack s;
	char* element;
	
	for(int i=0; arr[i]!=NULL; i++)
    {
        element=arr[i];
    	if((element!="+") && (element!="*") && (element!="(") && (element!=")"))
    	{
    		postfix[countPostfix]=element;
    		countPostfix++;
		}
		else if(element==")")
		{
			while(s.top()!="(")
			{
				postfix[countPostfix]=s.pop();
				countPostfix++;
			}
			s.pop();
			countStack--;
		}
		else
		{
    		while(s.isEmpty() && prcd(s.top(), element))
			{
				op=s.pop();
				postfix[countPostfix-1]=op;
				countPostfix++;
				countStack--;
			}
			s.push(element);
			countStack++;
		}
	}
	while(!s.isEmpty())
	{
		op=s.pop();
		postfix[countPostfix]=op;
		countPostfix++;
		countStack--;
	}
	postfix[countPostfix]='\0';
	
	cout<<"Postfix expression of given infix form is: ";
	for(int j=0; j<size-1; j++)
	{
		op=postfix[j];
		cout<<op;
	}
}