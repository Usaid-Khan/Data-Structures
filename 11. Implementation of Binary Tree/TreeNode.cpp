/*This file contains the TreeNode class declaration. TreeNode contains the functionality for a binary tree node*/

#include <stdlib.h>

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
};//end class TreeNode