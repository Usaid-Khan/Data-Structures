#include <iostream>
#include "Stack.cpp"
#include "TreeNode.cpp"
using namespace std;

/*Insert Function*/
void insert(TreeNode<int>* root, int* info)
{
	TreeNode<int>* node = new TreeNode<int>(info);
	TreeNode<int> *p, *q;
	
	p=q=root;
	
	while(*info!=*(p->getInfo()) && q!=NULL)
	{
		p=q;
		if(*info<*(p->getInfo()))
		{
			q=p->getLeft();
		}
		else if(*info>*(p->getInfo()))
		{
			q=p->getRight();
		}
	}
	
	if(*info==*(p->getInfo()))
	{
		cout<<"attempt to insert duplicate: "<<*info<<"\n";
		delete node;
	}
	else if(*info<*(p->getInfo()))
	{
		p->setLeft(node);
	}
	else
	{
		p->setRight(node);
	}
}//end of insert

/*Inorder Function (Non Recursive)*/
void inorder(TreeNode<int>* root) 
{ 

	Stack< TreeNode<int>* > stack; 
 	TreeNode<int>* p; 
 	p=root; 
 	do 
 	{
 		while(p!=NULL) 
 		{ 
 			stack.push(p); 
 			p=p->getLeft(); 
 		} 
 		// at this point, left tree is empty 
		if(!stack.empty()) 
 		{ 
 			p=stack.pop(); 
 			cout<<*(p->getInfo())<<" "; 
 			// go back & traverse right subtree 
 			p=p->getRight(); 
 		} 
 	}while(!stack.empty() || p!= NULL); 
}//end of inorder

main()
{
	int x[]={14,15,4,9,7,18,3,5,16,4,20,17,9,14,5,-1};
	TreeNode<int>* root = new TreeNode<int>();
	
	/*Setting Tree and also avoid duplicates*/
	root->setInfo(&x[0]);
	for(int i=1; x[i]>0; i++)
	{
		insert(root, &x[i]);
	}
	
	cout<<"\ninorder: ";
	inorder(root);        //inorder also ordering numbers
}