#ifndef GLOBAL_H

#define GLOBAL_H

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 114514


class graph
{
public:
	int dis;
	int to_code;
	char to_name;
	int next;
};

class node
{
public:
	char name;
	int code;
	int in_num;
	int dis;
	int head;
	int mark;
};
#endif