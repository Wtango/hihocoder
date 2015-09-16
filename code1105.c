#include <stdio.h>
#include <string.h>

#define MAXNODE 100010

int tree[MAXNODE] = {0};
int size = 0;

void swap(int n1,int n2)
{
	int tmp = tree[n1];
	tree[n1] = tree[n2];
	tree[n2] = tmp;
}

void add_node(int weight)
{
	tree[++size] = weight;
	int loc = size;
	while((loc > 1) && tree[loc] > tree[loc/2]) {
		swap(loc,loc/2);
		loc /= 2;
	}
}

int big_son(int node)
{
	int lnode = 2 * node;
	if(lnode + 1 > size)
		return lnode;
	return tree[lnode] > tree[lnode + 1]?lnode :lnode + 1;
	
}

int del_root()
{
	int root_weight = tree[1];
	tree[1] = tree[size--];
	int loc = 1;
	while((2 * loc <= size)) {
		int bs = big_son(loc);
		if(tree[loc] < tree[bs]) {
			swap(loc,bs);
			loc = bs;
			continue;
		}
		break;
	}
	return root_weight;
}

int main()
{
	char c;
	int N,weight;
	scanf("%d",&N);
	while(N--) {
		getchar();
		scanf("%c",&c);
		if(c == 'A') {
			scanf("%d",&weight);
			add_node(weight);
		}
		else
			printf("%d\n",del_root());
	}
}


