#include <iostream>
using namespace std;

class Queue{
	private:
		int size;
		int array[size];
		int front;
		int rear;
		int noElements;
		
	public:
		Queue()
		{
			size=8;
			array=NULL;
			front=0;
			rear=0;
			noElements=0;
		}
		
		void enqueue(int x);
		int dequeue();
		
		int isFull()
		{
			return (noElements==size);
		}
		int isEmpty()
		{
			return (noElements==0);
		}
};

/*Insert an element in the rear*/
void Queue::enqueue(int x)
{
	if(rear!=0)
	{
		rear=(rear+1)%size;
		array[rear]=x;
		noElements=noElements+1;
	}
	else
	{
		arrar[rear]=x;
		noElements=noElements+1;
	}
}

/*Remove element from the front*/
int Queue::dequeue()
{
	int x=array[front];
	front=(front+1)%size;
	noElements=noElements-1;
	return x;
}