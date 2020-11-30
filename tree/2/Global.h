#ifndef GLOBAL_H
#define GLOBAL_H

#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;

FILE* IN;
FILE* OUT;

class node
{
public:
	node* left, * right;
	bool is_child;
	unsigned char var;
	long long fre;
	
	node()
	{
		left = NULL;
		right = NULL;
		is_child = 0;
		var = 0;
		fre = 0;
	}
	node(int a, unsigned char b, int c)
	{
		left = NULL;
		right = NULL;
		is_child = a;
		var = b;
		fre = c;
	}
	node(int a, int c)
	{
		left = NULL;
		right = NULL;
		is_child = a;
		var = 0;
		fre = c;
	}
};
struct cmp
{
	bool operator() (const node* a, const node* b) {
		return a->fre > b->fre;
	}
};
struct Out_table
{
	unsigned char size;
	unsigned char var;
};
#endif