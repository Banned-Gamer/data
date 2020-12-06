#ifndef TOPO_H
#define TOPO_H

#include "Global.h"

class topo
{
private:
	node Node[1010];
	graph edge[N];
	int all_edge;//共有多少条边
	int num_edge;//边的编号，用于添加新边时使用
	int num_node;//点的数量
	int max_dis;//最远的距离
	int max_id;//最远的终点
	char char_node[1010];
	stack <int> path;
	
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

	/*
	 *name：pre_node
	 *function:初始化节点，将char_node中的名字和编号一一对应
	 */
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

	/*
	 *name:Topo_sort
	 *function:用拓扑排序来算最远距离
	 */
	void Topo_sort(int x)
	{
		int now = Node[x].head;
		int to;
		int dis;
		Node[x].mark = 1;
		while(now)//遍历x节点为起点的边
		{
			to = edge[now].to_code;
			dis = edge[now].dis;
			if (Node[to].dis < Node[x].dis + dis)//如果x的距离+id为now的边的长度大于到to的最大长度，则更新为此距离
			{
				Node[to].dis = Node[x].dis + dis;
				Node[to].father = x; //记录父节点，便于输出路径
				if(max_dis<Node[to].dis)
				{
					max_dis = max_dis > Node[to].dis ? max_dis : Node[to].dis;//求最远距离，同时存最远距离的终点
					max_id = to;
				}
				Node[to].in_num--;
				if (!Node[to].in_num && !Node[to].mark) {
					Topo_sort(to);//递归，子节点的入度为零就一直往下走
				}
			}
			now=edge[now].next;
		}
		return;
	}
	void Topo()
	{
		cout << "Input the number of node:" << endl;
		cin >> num_node;
		cout << "Input the number of edge:" << endl;
		cin >> all_edge;
		cout << "Input every node's name:" << endl;
		for (int i = 1; i <= num_node; i++)//录入节点
		{
			scanf(" %c", &char_node[i]);
			pre_node(char_node[i], i);
		}

		char u, v;
		int w;
		int u_code, v_code;//寻找u和v的编号
		for (int i = 1; i <= all_edge; i++)//录入边
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
			if (!Node[i].in_num && !Node[i].mark)//拓扑排序，遍历最原始的几个入度为0的点
			{
				max_dis = max_dis > Node[i].dis ? max_dis : Node[i].dis;
				Topo_sort(i);
			}
		}

		int now = max_id;
		path.push(now);
		while(Node[now].father)//用栈进行倒序遍历
		{
			now = Node[now].father;
			path.push(now);
		}
		cout << "The farthest way is:" << endl;
		while(!path.empty())
		{
			cout << path.top();
			path.pop();
			if (!path.empty())
			{
				cout << " > ";
			}
			else cout << '.' << endl;
		}
		cout << "The length is " << max_dis;
		return ;
	}
};


#endif