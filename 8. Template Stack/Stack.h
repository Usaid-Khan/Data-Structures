#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class Stack{
	private:
		int top;
		T* nodes;
		
	public:
		Stack();
		~Stack();
		
		int empty();		//1=true, 0=false
		int push(T&);		//1=successful, 0=stack overflow
		T pop();
		T peek();
};