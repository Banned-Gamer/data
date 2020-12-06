#ifndef TOPO_H
#define TOPO_H

#include "Global.h"

class topo
{
private:
	node Node[1010];
	graph edge[N];
	int all_edge;
	int num_edge;
	int num_node;
	int max_dis;
	int max_id;
	char char_node[1010];
	
public:
	void add_edge(int u,int v,int dis)
	{
		Node[v].in_num++;
		edge[++num_edge].next = Node[u].head;
		Node[u].head = num_edge;
		edge[num_edge].to_code = v;
		edge[num_edge].to_name = Node[v].name;
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
		int now = Node[x].head;
		int to;
		int dis;
		Node[x].mark = 1;
		while(now)
		{
			to = edge[now].to_code;
			dis = edge[now].dis;
			if (Node[to].dis < Node[x].dis + dis)
			{
				Node[to].dis = Node[x].dis + dis;
				Node[to].father = x;
				if(max_dis<Node[to].dis)
				{
					max_dis = max_dis > Node[to].dis ? max_dis : Node[to].dis;
					max_id = to;
				}
				Node[to].in_num--;
				if (!Node[to].in_num && !Node[to].mark) {
					Topo_sort(to);
				}
			}
			now=edge[now].next;
		}
		return;
	}
	void Topo()
	{
		cin >> num_node >> all_edge;
		for (int i = 1; i <= num_node; i++)
		{
			scanf(" %c", &char_node[i]);
			pre_node(char_node[i], i);
		}

		char u, v;
		int w;
		int u_code, v_code;
		for (int i = 1; i <= all_edge; i++)
		{
			cin >> u >> v >> w;
			u_code = 0; v_code = 0;
			for(int j=1;j<=num_node;j++)
			{
				if (u_code && v_code) break;
				if (char_node[j] == u) u_code = j;
				if (char_node[j] == v) v_code = j;
			}
			add_edge(u_code, v_code, w);
		}
		max_dis = 0;
		for (int i = 1; i <= num_node; i++)
		{
			if (!Node[i].in_num && !Node[i].mark)
			{
				max_dis = max_dis > Node[i].dis ? max_dis : Node[i].dis;
				Topo_sort(i);
			}
		}

		int now = max_id;
		while (Node[now].father != 0)
		{
			now = Node[now].father;
		}
		printf("The farthest distant is from %c to %c, it's length is %d.", Node[now].name, Node[max_id].name, max_dis);
		return ;
	}
};


#endif