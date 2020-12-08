#ifndef MAKE_TREE_H
#define MAKE_TREE_H

#include "Global.h"

class make_tree
{
private:
	tree* root;
	int x;
	int long_char;
public:
	void pre_tree()
	{
		tree* node = new tree(char_all[0]);
		root = node;
		x = 1;
		long_char = strlen(char_all);
		return;
	}
	void add_tree(tree* now)
	{
		if (x < long_char) return;
		if (char_all[++x] != '*')
		{
			now->left = new tree(char_all[x]);
			now->num_child++;
			add_tree(now->left);
		}
		if (char_all[++x] != 'x')
		{
			now->right = new tree(char_all[x]);
			now->num_child++;
			add_tree(now->right);
		}
		return;
	}
	void print(tree* now)
	{
		cout << now->data;
		if(now->num_child)
		{
			cout << ",(";
			if (now->left != NULL)
			{
				print(now->left);
			}
			if (now->num_child == 2)
			{
				cout << ',';
			}
			if (now->right != NULL)
			{
				print(now->right);
			}
			cout << ")";
		}
		return;
	}
	void Make_tree()
	{
		pre_tree();
		add_tree(root);
		print(root);
		return;
	}
};

#endif