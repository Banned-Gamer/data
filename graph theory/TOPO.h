#ifndef TOPO_H
#define TOPO_H

#include "Global.h"

class topo
{
private:
	node Node[1010];
	graph edge[N];
	int num_edge;
	int num_node;
	int max_dis;
	char char_node[1010];
	
public:
	void add_edge(node u,node v,int dis)
	{
		v.in_num++;
		edge[++num_edge].next = u.head;
		u.head = num_edge;
		edge[num_edge].to_name = v.name;
		edge[num_edge].dis = dis;
		return;
	}
	void pre_node(char cc,int i)
	{
		Node[i].name = cc;
		Node[i].code = i;
		Node[i].in_num = 0;
		Node[i].dis = 0;
		Node[i].head = 0;
		Node[i].mark = 0;
		return;
	}
	void Topo_sort(int x)
	{
		int temp = Node[x].head;
		while(temp)
		{
			if(Node[edge[temp].to_code].dis<Node[x].dis+edge[temp].dis)
			{
				Node[edge[temp].to_code].dis = Node[x].dis + edge[temp].dis;
				max_dis = max_dis > Node[edge[temp].to_code].dis ? max_dis : Node[edge[temp].to_code].dis;
				Node[edge[temp].to_code].in_num--;
			}
		}
		Node[x].mark = 1;
		return;
	}
	int Topo()//剩余有多少点
	{
		cin >> num_node >> num_edge;
		for (int i = 1; i <= num_node; i++)
		{
			cin >> char_node[i];
			pre_node(char_node[i], i);
		}

		char u, v;
		int w;
		int u_code, v_code;
		for (int i = 1; i <= num_edge; i++)
		{
			cin >> u >> v;
			u_code = 0; v_code = 0;
			for(int j=1;j<=num_node;j++)
			{
				if (u_code && v_code) break;
				if (char_node[j] == u) u_code = j;
				if (char_node[j] == v) v_code = j;
			}
			add_edge(Node[u_code], Node[v_code], w);
		}

		max_dis = 0;
		
		for(int i=1;i<=num_node;i++)
		{
			if (!Node[i].in_num && !Node[i].mark)
			{
				max_dis = max_dis > Node[i].dis ? max_dis : Node[i].dis;
				Topo_sort(i);
			}
		}
		return max_dis;
	}
};


#endif