#include "Global.h"
#include "TOPO.h"
using namespace std;
int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	topo TOPO;
	cout << TOPO.Topo();
	return 0;
}