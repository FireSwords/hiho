#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e4+1;
const int M = 1e5;
const int INF = 0x3fffffff;

struct Edge{
	int to,w;
	Edge* next;
};
Edge e[M*2], *p[N]={NULL};
int use[N], ans[N];

void addEdge(int u, int v, int w) {
	static int i = 0;
	e[i].to = v;
	e[i].w = w;
	e[i].next = p[u];
	p[u] = &e[i];
	i++;
}

bool path(int o, int t, int k) {
	if (o==t) return true;
	if (k<=0 && o!=t) return false;
	
	Edge *e;
	bool flag=false;
	for (e=p[o]; e!=NULL; e=e->next) {
		if (e->to==o) continue;
		if (use[e->to]) continue;
		if (e->w>=ans[o] || e->w>=ans[1]) continue;
		int to = e->to;
		use[to] = 1;
		if (path(to,t,k-1)) {
			ans[o] = min(ans[o], max(e->w,ans[to]));
			flag = true;
		}
		use[to] = 0;
	}
	return flag;
}

int main() {	
	int n,m,k,t,i,u,v,w;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for (i=0; i<m; ++i) {
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	for (i=1; i<=n; ++i)
		ans[i] = INF;
	
	ans[t] = 0;
	use[1] = 1;
	path(1,t,k);
	printf("%d\n", ans[1]);
}
