#ifndef ENCODE_H
#define ENCODE_h

#include "Global.h"

#define N 114514

struct tree
{
	char a;
	int data;
	tree *left, *right;

	bool operator < (const tree& b)const
	{
		return data < b.data;
	}
};

char in[N];
int n;
priority_queue<tree*>huff;

void pre_tree(char,int);
void huffman1();
void huffman2(tree*);
void encode();


#endif