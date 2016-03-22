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
int ans[N];

void addEdge(int u, int v, int w) {
	static int i = 0;
	e[i].to = v;
	e[i].w = w;
	e[i].next = p[u];
	p[u] = &e[i];
	i++;
}

void dfs(int o, int k) {
	if (k==0) return;
	
	Edge *e;
	for (e=p[o]; e!=NULL; e=e->next) {
		int to = e->to;
		ans[to] = min(ans[to], max(e->w,ans[o]));
		dfs(to, k-1);
	}
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
	dfs(t,k);
	printf("%d\n", ans[1]);
}
