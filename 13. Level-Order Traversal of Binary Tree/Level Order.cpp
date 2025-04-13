#include <iostream>
#include <stdlib.h>
#include <queue>
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

/*Level Order Function*/
void levelorder(TreeNode<int>* treeNode)
{
	queue< TreeNode<int>* > q;
	
	if(treeNode==NULL)
	{
		return;
	}
	
	q.push(treeNode);
	while(!q.empty())
	{
		treeNode=q.front();
		q.pop();
		cout<<*(treeNode->getInfo())<<" ";
		if(treeNode->getLeft()!=NULL)
		{
			q.push(treeNode->getLeft());
		}
		if(treeNode->getRight()!=NULL)
		{
			q.push(treeNode->getRight());
		}
	}
}//end of levelorder

int main()
{
	int x[]={14,15,4,9,7,18,3,5,16,4,20,17,9,14,5,-1};
	TreeNode<int>* root = new TreeNode<int>();
	
	/*Setting Tree and also avoid duplicates*/
	root->setInfo(&x[0]);
	for(int i=1; x[i]>0; i++)
	{
		insert(root, &x[i]);
	}
	
	cout<<"\nlevelorder: ";
	levelorder(root);        //inorder also ordering numbers
}