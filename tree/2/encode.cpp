#include "encode.h"
void pre_tree(char x,int long_x	)
{
	tree* now;
	now->data = long_x;
	now->a = x;
	now->left = NULL;
	now->right = NULL;
	huff.push(now);
	return;
}
void huffman1()
{
	tree* now1, * now2;
	while(huff.size()>1)
	{
		now1 = huff.top();
		huff.pop();
		now2 = huff.top();
		huff.pop();
		tree* new_tree;
		new_tree = new_tree;
		new_tree->data = now1->data + now2->data;
		new_tree->left = now1;
		new_tree->right = now2;
		huff.push(new_tree);
	}
	now1 = huff.top();
	huffman2(now1);
}
void huffman2(tree* now)
{
	if (now->left != NULL)
	{
		tree* left = now->left;
		left->data = now->data << 1;
		huffman2(left);
	}
	if (now->right != NULL)
	{
		tree* right = now->right;
		right->data = (now->data << 1) + 1;
		huffman2(right);
	}
	return;
}
void encode()
{
	
}