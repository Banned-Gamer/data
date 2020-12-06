/*
 *code : the farthest way
 *auther : banned
 *time : 2020/12/6
 *algorithm : 采用拓扑排序，我们只考虑从某一节点到当前节点的最远距离，由于是有向无环图，
 *			  所以入度为0的点说明最远距离为0，然后根据点遍历边，到达子节点就判断是否起点
 *			  的最远距离加边的长度大于子节点的最远距离，然后替换就行了
 */


#include "Global.h"
#include "TOPO.h"
using namespace std;
int main()
{
	topo TOPO;
	TOPO.Topo();
	return 0;
}