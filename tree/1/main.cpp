#include<iostream>
#include<cstring>
using namespace std;

#define N 114514

struct tree{
    char data;
    tree *left,*right;
};
typedef tree* node;

node head;
char a_tree[N];
int x,long_tree;
void pre_tree(){
    node list;
	list = new tree;
    list->left = NULL;
    list->right = NULL;
    head = list;
    return;
}

void node_tree(node now)
{
    if (a_tree[x] == '*') return;
	
    node next;

	/*********������������**********/
    next = new tree;
    next->left = NULL;
    next->right = NULL;
    next->data = a_tree[x++];
    now->left = next;
    node_tree(next);

	/*********������������**********/
    next = new tree;
    next->left = NULL;
    next->right = NULL;
    if (a_tree[x] != '*') next->data = a_tree[x++];
    else return;
    now->right = next;
    node_tree(next);
	
	return;
}

void add_tree()
{
    cin >> a_tree;
    long_tree = strlen(a_tree);
    pre_tree();
    node_tree(head);
    return;
}

void print(node now)
{
    cout << now->data;

    int flag1 = (now->left == NULL);
    int flag2 = (now->right == NULL);
    if (flag1 && flag2)
    {
        cout << ")";
        return;
    }
    cout << ",(";
    if (!flag1) print(now->left);
    if ((!flag1) && (!flag2)) cout << ",";
    if (!flag2) print(now->right);
    return;
}

int main(){
    add_tree();
    print(head);
    return 0;
}