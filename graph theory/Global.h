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
private:
	struct edge
	{
		int dis;
		int to;
		int next;
	}e[N];

	int num_edge;
	int head_edge[N];
public:
	void add_edge(int u,int v,int w)
	{
		e[++num_edge].next = head_edge[u];
		head_edge[u] = num_edge;
		e[num_edge].to = v;
		e[num_edge].dis = w;
		return;
	}
};

#endif