#include <iostream>
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
