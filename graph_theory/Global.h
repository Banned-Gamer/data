#ifndef GLOBAL_H

#define GLOBAL_H

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 114514


struct graph
{
	int dis;//距离
	int to_code;//终点编号
	char to_name;//终点的名字
	int next;//下一条边
};

struct node
{
	char name;//本点的名字
	int code;//编号，便于进行遍历
	int in_num;//入度，用于拓扑排序
	int dis;//最远的点到此点的距离
	int head;//首边编号
	int mark;//是否进栈（删除节点）
	int father;//最远的点的编号
};
#endif