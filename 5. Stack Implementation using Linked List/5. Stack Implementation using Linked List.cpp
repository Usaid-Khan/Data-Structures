#include <iostream>
#include <stdlib.h>
#include "Node.cpp"
using namespace std;

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
		
		int pop();
		void push(int x);
		int top();
		int isEmpty();
		
};

/*pop method*/
int Stack::pop()
{
	int temp=head->get();
	Node* p=head;
	head=head->getNext();
	delete p;
	size--;
	return temp;
}

/*push method*/
void Stack::push(int x)
{
	Node* newNode = new Node();
	newNode->set(x);
	newNode->setNext(head);
	head=newNode;
	size++;
}

/*top method*/
int Stack::top()
{
	return head->get();
}

/*isEmpty method*/
int Stack::isEmpty()
{
	return (head==NULL);
}

int main()
{
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}