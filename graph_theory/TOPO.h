#ifndef TOPO_H
#define TOPO_H

#include "Global.h"

class topo
{
private:
	node Node[1010];
	graph edge[N];
	int all_edge;//���ж�������
	int num_edge;//�ߵı�ţ���������±�ʱʹ��
	int num_node;//�������
	int max_dis;//��Զ�ľ���
	int max_id;//��Զ���յ�
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
	 *name��pre_node
	 *function:��ʼ���ڵ㣬��char_node�е����ֺͱ��һһ��Ӧ
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
	 *function:����������������Զ����
	 */
	void Topo_sort(int x)
	{
		int now = Node[x].head;
		int to;
		int dis;
		Node[x].mark = 1;
		while(now)//����x�ڵ�Ϊ���ı�
		{
			to = edge[now].to_code;
			dis = edge[now].dis;
			if (Node[to].dis < Node[x].dis + dis)//���x�ľ���+idΪnow�ıߵĳ��ȴ��ڵ�to����󳤶ȣ������Ϊ�˾���
			{
				Node[to].dis = Node[x].dis + dis;
				Node[to].father = x; //��¼���ڵ㣬�������·��
				if(max_dis<Node[to].dis)
				{
					max_dis = max_dis > Node[to].dis ? max_dis : Node[to].dis;//����Զ���룬ͬʱ����Զ������յ�
					max_id = to;
				}
				Node[to].in_num--;
				if (!Node[to].in_num && !Node[to].mark) {
					Topo_sort(to);//�ݹ飬�ӽڵ�����Ϊ���һֱ������
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
		for (int i = 1; i <= num_node; i++)//¼��ڵ�
		{
			scanf(" %c", &char_node[i]);
			pre_node(char_node[i], i);
		}

		char u, v;
		int w;
		int u_code, v_code;//Ѱ��u��v�ı��
		for (int i = 1; i <= all_edge; i++)//¼���
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
			if (!Node[i].in_num && !Node[i].mark)//�������򣬱�����ԭʼ�ļ������Ϊ0�ĵ�
			{
				max_dis = max_dis > Node[i].dis ? max_dis : Node[i].dis;
				Topo_sort(i);
			}
		}

		int now = max_id;
		path.push(now);
		while(Node[now].father)//��ջ���е������
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