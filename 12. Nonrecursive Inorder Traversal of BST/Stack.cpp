#include <iostream>
#include <stdlib.h>
#include "Stack.h"
#define MAXSTACKSIZE 50
using namespace std;

template <class T>
Stack<T>::Stack()
{
	top=-1;
	nodes = new T[MAXSTACKSIZE];
}

template<class T>
Stack<T>::~Stack()
{
	delete nodes;
}

template<class T>
int Stack<T>::empty()
{
	if(top<0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>
int Stack<T>::push(T& x)
{
	if(top<MAXSTACKSIZE)
	{
		nodes[++top]=x;
		return 1;
	}
	cout<<"stack overflow in push.\n";
	return 0;
}

template<class T>
T Stack<T>::pop()
{
	T x;
	if(!empty())
	{
		x=nodes[top--];
		return x;
	}
	cout<<"stack overflow in pop.\n";
	return x;	
}

template<class T>
T Stack<T>::peek()
{
	T x;
	if(!empty())
	{
		x=nodes[top];
		return x;
	}
	cout<<"stack overflow in top.\n";
	return x;
}