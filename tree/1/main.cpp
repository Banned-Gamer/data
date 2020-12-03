#include <iostream>
using namespace std;

#define N 114514

struct tree
{
	char data;
	int is_brother;
	tree* left, * right;
};

tree* head;
int tree_long;
char tree_char[N];
int x;

void pre_tree()
{
	tree* node = new tree;
	node->data = tree_char[0];
	node->is_brother = 0;
	node->left = NULL;
	node->right = NULL;
	head = node;
	return;
}

void add_tree(tree* now)
{
	if (tree_char[x] == '*') return;
	now->left = new tree;
	now->left->data = tree_char[x++];
	now->left->left = NULL;
	now->left->right = NULL;
	if (tree_char[x] == '*') now->left->is_brother = 0;
	else now->left->is_brother = 1;
	add_tree(now->left);

	if (tree_char[x] == '*') return;
	now->right = new tree;
	now->right->data = tree_char[x++];
	now->right->left = NULL;
	now->right->right = NULL;
	if (tree_char[x - 1] == '*')now->right->is_brother = 0;
	else now->right->is_brother = 2;
	add_tree(now->right);

	return;
}

void print(tree* now)
{
	int flag1 = 0, flag2 = 0;
	if (now->left == NULL) flag1 = 1;
	if (now->right == NULL) flag2 = 1;
	
	cout << ' ' << now->data;
	if ((!flag1) || (!flag2))
	{
		cout << ",(";
	}
	if(!flag1)
	{
		print(now->left);
	}
	if(!flag2)
	{
		print(now->right);
	}
	if (now->is_brother == 0)
	{
		cout << ").";
	}
	if (now->is_brother == 1)
	{
		cout << ',';
	}
	if(now->is_brother==2)
	{
		cout << ").";
	}
	return;
}
int main()
{
	cin >> tree_char;
	x = 1;
	pre_tree();
	add_tree(head);
	print(head);
	return 0;
}