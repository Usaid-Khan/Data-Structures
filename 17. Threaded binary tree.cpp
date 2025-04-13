#include <iostream>
#include <stdlib.h>
using namespace std;

static string dummy="dummy", thread="thread", child="child";
static int dummyVal=999;

template <class T>
class TreeNode {
private:
    T* data;
    TreeNode* left;
    TreeNode* right;
    string Lth;
    string Rth;

public:
    TreeNode() {
        data=NULL;
        left=right=NULL;
        Lth=Rth="thread";
    }
    TreeNode(T* data)
	{
        this->data=data;
        this->left=this->right=NULL;
        this->Lth=this->Rth="thread";
    }

    void setInfo(T* data)
	{
        this->data=data;
    }
    T* getInfo()
	{
        return data;
    }
    void setLeft(TreeNode* left)
	{
        this->left=left;
    }
    TreeNode* getLeft()
	{
        return left;
    }
    void setRight(TreeNode* right)
	{
        this->right=right;
    }
    TreeNode* getRight()
	{
        return right;
    }
    void setLth(string Lth)
	{
        this->Lth=Lth;
    }
    string getLth()
	{
        return Lth;
    }
    void setRth(string Rth)
	{
        this->Rth=Rth;
    }
    string getRth() 
	{
        return Rth;
    }
};

TreeNode<int>* dummyNode = new TreeNode<int>(&dummyVal);

void insert(TreeNode<int>*& root, int* info)
{
    TreeNode<int>* newNode = new TreeNode<int>(info);
    TreeNode<int>* p, * q;
    p=q=root;

    if(root->getInfo()==NULL)
	{
        root=newNode;
        root->setLeft(dummyNode);
        root->setLth(thread);
        root->setRight(dummyNode);
        root->setRth(thread);
        dummyNode->setLeft(root);
        dummyNode->setLth(child);
        dummyNode->setRight(root);
        dummyNode->setRth(child);
    }
    else
	{
        while(*(newNode->getInfo())!=*(p->getInfo()) && (q->getLth()==child || q->getRth()==child))
		{
            p=q;
            if(*(newNode->getInfo())<*(p->getInfo()) && (p->getLth()==child))
			{
                q=p->getLeft();
            }
            else if (*(newNode->getInfo())>*(p->getInfo()) && (p->getRth()==child))
			{
                q=p->getRight();
            }
        }

        if (*(newNode->getInfo())==*(p->getInfo()))
		{
            cout<<"duplicate value: "<<*(newNode->getInfo())<<"\n";
            delete newNode;
        }
        else if(*(newNode->getInfo())<*(p->getInfo()))
		{
            newNode->setLeft(p->getLeft());
            newNode->setLth(thread);
            newNode->setRight(p);
            newNode->setRth(thread);
            p->setLeft(newNode);
            p->setLth(child);
        }
        else
		{
            newNode->setRight(p->getRight());
            newNode->setRth(thread);
            newNode->setLeft(p);
            newNode->setLth(thread);
            p->setRight(newNode);
            p->setRth(child);
        }
    }
}

TreeNode<int>* nextInorder(TreeNode<int>* p)
{
    if(p->getRth()=="thread")
	{
        return (p->getRight());
    }
    else
	{
        p=p->getRight();
        while(p->getLth()=="child")
		{
            p=p->getLeft();
        }
        return p;
    }
}

void fastInorder(TreeNode<int>* root)
{
    while(root!=dummyNode)
	{
        cout<<*(root->getInfo())<<" ";
        root=nextInorder(root);
    }
}
