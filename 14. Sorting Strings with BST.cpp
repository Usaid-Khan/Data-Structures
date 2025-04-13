#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

template <class Object>
class TreeNode{
	private:
		Object* object;
		TreeNode* left;
		TreeNode* right;
	
	public:
		/*Non-Parameterized Constructor*/
		TreeNode()
		{
			this->object=NULL;
			this->left=this->right=NULL;
		}
		/*Parameterized Constructor*/
		TreeNode(Object* object)
		{
			this->object=object;
			this->left=this->right=NULL;
		}
		/*Destructor*/
		~TreeNode()
		{
			delete object;
			delete left;
			delete right;
		}
		
		Object* getInfo()
		{
			return this->object;
		}
		void setInfo(Object* object)
		{
			this->object=object;
		}
		
		TreeNode* getLeft()
		{
			return left;
		}
		void setLeft(TreeNode* left)
		{
			this->left=left;
		}
		
		TreeNode* getRight()
		{
			return right;
		}
		void setRight(TreeNode* right)
		{
			this->right=right;
		}
		
		int isLeaf()
		{
			if(this->left==NULL && this->right==NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};// end class TreeNode

/*Insert Function*/
void insert(TreeNode<char>* root, char* info)
{
	TreeNode<char>* node = new TreeNode<char>(info);
	TreeNode<char> *p, *q;
	
	p=q=root;
	
	while(strcmp(info, p->getInfo())!=0 && q!=NULL)
	{
		p=q;
		if(strcmp(info, p->getInfo())<0)
		{
			q=p->getLeft();
		}
		else
		{
			q=p->getRight();
		}
	}
	
	if(strcmp(info, p->getInfo())==0)
	{
		cout<<"attempt to insert duplicate: "<<*info<<"\n";
		delete node;
	}
	else if(strcmp(info, p->getInfo())<0)
	{
		p->setLeft(node);
	}
	else
	{
		p->setRight(node);
	}
}//end of insert

/*Inorder Function*/
void inorder(TreeNode<char>* treeNode)
{
	if(treeNode!=NULL)
	{
		inorder(treeNode->getLeft());
		cout<<(treeNode->getInfo())<<"\n";
		inorder(treeNode->getRight());
	}
}//end of inorder

void wordTree()
{
	TreeNode<char>* root = new TreeNode<char>();
	static char* word[]={"babble","fable","jacket",
	"backup","eagle","daily","gain","bandit","abandon",
	"abash","accuse","economy","adhere","advise","cease",
	"debunk","feeder","genius","fetch","chain",NULL};
	
	root->setInfo(word[0]);
	for(int i=1; word[i]; i++)
	{
		insert(root, word[i]);
	}
	
	inorder(root);
	cout<<"\n";
}

int main()
{
	wordTree();
}