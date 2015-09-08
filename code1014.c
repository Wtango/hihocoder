#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct TrieNode{
	struct TrieNode *childNode;
	char nodeChar;
	int count;
	uint8_t word_flag;	
}trie_node_t;

void init_node(trie_node_t *node,char nodeChar,uint8_t word_flag)
{
	node->childNode = (trie_node_t*)malloc(sizeof(trie_node_t) * 26);
	memset(node->childNode,0,sizeof(trie_node_t) * 26);
	node->nodeChar = nodeChar;
	node->count = 0;
	node->word_flag = word_flag;
}

void add_trie_node(trie_node_t *root,const char *word,size_t len)
{
	if(len == 0)
		return;
	int k = word[0] - 'a';
	if(root->childNode[k].nodeChar == 0){
		init_node(&(root->childNode[k]),word[0],len == 1?1:0);
	}
	root->childNode[k].count += 1;
	add_trie_node(&(root->childNode[k]),++word,--len);
}

int search_tree(trie_node_t *root,const char *word,size_t len)
{
	if(len == 0)
		return 0;
	int k = word[0] - 'a';
	if(root->childNode[k].nodeChar == word[0]) {
		if(len == 1) {
				return root->childNode[k].count;
		}
		else {
			return search_tree(&(root->childNode[k]),++word,--len);
		}
	}
	return 0;
}

int main(int argc,char *argv[])
{
	int times;
	char buf[11] = {0};
	trie_node_t root;
	init_node(&root,0,0);
	for(scanf("%d",&times);times != 0;times--) {
		scanf("%s",buf);
		add_trie_node(&root,buf,strlen(buf));
	}
	for(scanf("%d",&times);times != 0;times--) {
		scanf("%s",buf);
		int num = search_tree(&root,buf,strlen(buf));
		printf("%d\n",num);
	}
	return 0;
}
