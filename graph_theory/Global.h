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
	int dis;//����
	int to_code;//�յ���
	char to_name;//�յ������
	int next;//��һ����
};

struct node
{
	char name;//���������
	int code;//��ţ����ڽ��б���
	int in_num;//��ȣ�������������
	int dis;//��Զ�ĵ㵽�˵�ľ���
	int head;//�ױ߱��
	int mark;//�Ƿ��ջ��ɾ���ڵ㣩
	int father;//��Զ�ĵ�ı��
};
#endif