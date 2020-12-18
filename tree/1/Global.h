#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 114514

char char_all[N];

class tree
{
public:
	char data;
	int num_child;
	tree* left, * right;

	tree(char char_data)
	{
		data = char_data;
		num_child = 0;
		left = NULL;
		right = NULL;
		return;
	}
};



#endif
