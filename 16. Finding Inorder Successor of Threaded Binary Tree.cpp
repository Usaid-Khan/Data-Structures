#include <iostream>
using namespace std;

TreeNode* nextInorder(TreeNode* p)
{
	if(p->RTH==thread)
	{
		return (p->R);
	}
	else
	{
		p=p->R;
		while(p->LTH==child)
		{
			p=p->L;
		}
		return p;
	}
}