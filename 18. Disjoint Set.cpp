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
	int j;
	for(j=i; parent[j]>=0; j=parent[j])
	{
		;
	}
	return j;
}

void DisjointSet::unionDisjoint(int i, int j)
{
	int root_i=find(i);
	int root_j=find(j);
	if(root_i!=root_j)
	{
		parent[root_j]=root_i;
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
}