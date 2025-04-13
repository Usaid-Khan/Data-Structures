#include <iostream>
#include <stdlib.h>
#include "TreeNode.cpp"
#include "BinaryTree.cpp"
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
		else
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

/*Find Function*/
int find(TreeNode<int>* root, int* info)
{
	int count=-1;
	TreeNode<int> *p, *q;
	p=q=root;
	
	while(*info!=*(p->getInfo()) && q!=NULL)
	{
		p=q;
		if(*info<*(p->getInfo()))
		{
			q=p->getLeft();
		}
		else
		{
			q=p->getRight();
		}
		count++;
	}
		
	if(*info==*(p->getInfo()))
	{
		cout<<"\nThis item is found at level: "<<count<<"\n\n";
		return true;
	}
	else
	{
		cout<<"\nThis item is not\n";
		return false;
	}
}//end of find

/*Preorder Function*/
void preorder(TreeNode<int>* treeNode)
{
	if(treeNode!=NULL)
	{
		cout<<*(treeNode->getInfo())<<" ";
		preorder(treeNode->getLeft());
		preorder(treeNode->getRight());
	}
}//end of preorder

/*Inorder Function*/
void inorder(TreeNode<int>* treeNode)
{
	if(treeNode!=NULL)
	{
		inorder(treeNode->getLeft());
		cout<<*(treeNode->getInfo())<<" ";
		inorder(treeNode->getRight());
	}
}//end of inorder

/*Postorder Function*/
void postorder(TreeNode<int>* treeNode)
{
	if(treeNode!=NULL)
	{
		postorder(treeNode->getLeft());
		postorder(treeNode->getRight());
		cout<<*(treeNode->getInfo())<<" ";
	}
}//end of postorder

TreeNode<int>* findMin(TreeNode<int>* tree);	//Forward declaration
/*This method is used to remove a node from BST*/
TreeNode<int>* remove(TreeNode<int>* tree, int info)
{
	int cmp;
	TreeNode<int>* t;
	cmp=info-*(tree->getInfo());
	if(cmp<0)		//Node to delete in left subtree
	{
		t=remove(tree->getLeft(), info);
		tree->setLeft(t);
	}
	else if(cmp>0)		//Node to delete in right subtree
	{
		t=remove(tree->getRight(), info);
		tree->setRight(t);
	}
	else if(tree->getLeft()!=NULL && tree->getRight()!=NULL)	//two children, replace with inorder successor (handles case 3)
	{
		TreeNode<int>* minNode;
		minNode=findMin(tree->getRight());
		tree->setInfo(minNode->getInfo());
		t=remove(tree->getRight(), *(minNode->getInfo()));
		tree->setRight(t);
	}
	else	//handles case 1 and case 2
	{
		TreeNode<int>* nodeToDelete=tree;
		if(tree->getLeft()==NULL)
		{
			tree=tree->getRight();
		}
		else if(tree->getRight()==NULL)
		{
			tree=tree->getLeft();
		}
		else
		{
			tree=NULL;
		}
		delete nodeToDelete;
	}
	return tree;
}

/*This method is used to find the minimun node in a tree*/
TreeNode<int>* findMin(TreeNode<int>* tree)
{
	if(tree==NULL)
	{
		return NULL;
	}
	while(tree->getLeft()!=NULL)
	{
		tree=tree->getLeft();
	}
	return tree;
}

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
	
	/*Searching item*/
	int search=17;
	find(root, &search);
	
	/*Traversing tree*/
	cout<<"preorder: ";
	preorder(root);
	
	cout<<"\ninorder: ";
	inorder(root);        //inorder also ordering numbers
	
	remove(root, 18);
	cout<<"\nafter removing 18: ";
	inorder(root);
	
	cout<<"\npostorder: ";
	postorder(root);
	
	/*finding minimum*/
	TreeNode<int>* n=findMin(root);
	cout<<"\nMinimum value is: "<<*(n->getInfo())<<"\n";
}