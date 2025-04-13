#include <iostream>
using namespace std;

class Stack{
	private:
		int object;
		int current;
		int size;
		int A[10];
		
	public:
		Stack()
		{
			size=10;
			current=-1;
		}
		
		int pop()
		{
			return A[current--];
		}
		void push(int x)
		{
			A[++current]=x;
		}
		int top()
		{
			return A[current];
		}
		int isEmpty()
		{
			return A[current==-1];
		}
		int isFull()
		{
			return A[current==size-1];
		}
};

int main()
{
	Stack stack;
	
	/*pushing the 10 elements to the stack*/
	for(int i=0; i<12; i++)
	{
		if(!stack.isFull())    //checking stack is full or not.
		{
			stack.push(i);
		}
		else
		{
			cout<<"Stack is full, can't insert new element\n";
		}
	}
	
	/*pop the elements at the stack*/
	for(int i=0; i<12; i++)
	{
		if(!stack.isEmpty())    //checking stack is empty or not.
		{
			cout<<"The popped element = "<<stack.pop()<<"\n";
		}
		else
		{
			cout<<"Stack is empty, can't pop\n";
		}
	}
}