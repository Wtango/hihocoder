/*******************************************
http://hihocoder.com/problemset/problem/1049
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char c;
	struct node *left;
	struct node *right;
}node_t;


node_t* tree(const char *str1,const char *str2)
{
	int len = strlen(str1);
	if(len == 0)
		return NULL;
	node_t *node = (node_t*)malloc(sizeof(node_t));
	node->c = str1[0];
	char lpre[30];
	char lmid[30];
	memset(lpre,0,30);
	memset(lmid,0,30);
	int count=0;
	while(str2[count] != str1[0])
		count++;
	strncpy(lpre,str1+1,count);
	strncpy(lmid,str2,count);
	node->left = tree(lpre,lmid);
	char rpre[30];
	char rmid[30];
	memset(rpre,0,30);
	memset(rmid,0,30);
	strncpy(rpre,str1+1+count,len-count-1);
	strncpy(rmid,str2+count+1,len-count-1);
	node->right = tree(rpre,rmid);
	return node;
}

void ans(node_t *node)
{
	if(node->left != NULL)
		ans(node->left);
	if(node->right != NULL)
		ans(node->right);
	printf("%c",node->c);
}

int main()
{
	node_t *root;
	char str1[30];
	char str2[30];
	scanf("%s%s",str1,str2);
	root = tree(str1,str2);
	ans(root);
	return 0;
}
