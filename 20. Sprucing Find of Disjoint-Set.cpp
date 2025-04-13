#include <iostream>
#include <stdlib.h>
using namespace std;

class DisjointSet{
	private:
		int *parent;
		int size;
	
	public:
		DisjointSet(int);
		~DisjointSet();
		
		int find(int);
		void unionDisjoint(int, int);
};

DisjointSet::DisjointSet(int n) : size(n)
{
	parent = new int[size];
	for(int i=0; i<size; i++)
	{
		parent[i]=-1;
	}
}

DisjointSet::~DisjointSet()
{
	delete[] parent;
}

int DisjointSet::find(int i)
{
	if(parent[i]<0)
	{
		return i;
	}
	else
	{
		return parent[i]=find(parent[i]);
	}
}

void DisjointSet::unionDisjoint(int i, int j)
{
	int root_i=find(i);
	int root_j=find(j);
	
	if(root_i!=root_j)
	{
		if(parent[root_i]<=parent[root_j])		//comparing sizes of array indexes
		{
			/*first tree has more nodes or equal to other*/
			parent[root_i]+=parent[root_j];
			parent[root_j]=root_i;
		}
		else
		{
			/*second tree has more nodes*/
			parent[root_j]+=parent[root_i];
			parent[root_i]=root_j;
		}
	}
}

main()
{
	DisjointSet ds(9);
	
	ds.unionDisjoint(5, 6);
	ds.unionDisjoint(7, 8);
	ds.unionDisjoint(5, 7);
	ds.unionDisjoint(3, 4);
	ds.unionDisjoint(4, 5);
	int root=ds.find(8);
	cout<<"root is: "<<root<<"\n";
	
	DisjointSet ds2(9);
	
	ds2.unionDisjoint(4, 6);
	ds2.unionDisjoint(2, 3);
	ds2.unionDisjoint(1, 4);
	ds2.unionDisjoint(2, 4);
	ds2.unionDisjoint(5, 4);
	int root2=ds2.find(3);
	cout<<"root is: "<<root2<<"\n";
}