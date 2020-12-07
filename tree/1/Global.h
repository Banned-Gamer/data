#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <cstdio>

using namespace std;

#define N 114514

char char_all[N];

class tree
{
public:
	char data;
	int is_brother;
	tree* left, * right;

	tree(char char_data, int x)
	{
		data = char_data;
		is_brother = x;
		left = NULL;
		right = NULL;
		return;
	}
};



#endif
