#include "Stack.cpp"
int main()
{
	Stack<int> intStack;
	Stack<char> charStack;
	int x=10, y=20;
	char c='C', d='D';
	
	intStack.push(x); intStack.push(y);
	cout<<"intStack: "<<intStack.pop()<<", "<<intStack.pop()<<"\n";
	charStack.push(c); charStack.push(d);
	cout<<"charStack: "<<charStack.pop()<<", "<<charStack.pop()<<"\n";
}