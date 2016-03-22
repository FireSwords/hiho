#include <cstdio>
#include <cstring>

const int N = 15;
struct Edge {
	int to;
	Edge *next;
};
Edge *p[N];
int n,vis[N],start=1,toStart[N];

void addEdge(int u,int v) {
	Edge *e = new Edge();
	e->to = v;
	e->next = p[u];
	p[u] = e;
}

int dfs(int u,int d) {
	if (d==n) {
		if (toStart[u]) return 1;
		else return 0;
	}
	int cnt = 0;
	for (Edge* e=p[u]; e; e=e->next) {
		int v = e->to;
		if (vis[v]) continue;
		vis[v] = 1;
		cnt += dfs(v, d+1);
		vis[v] = 0;
	}
	return cnt;
}

int main() {
	int m,u,v;
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		if (u==1) toStart[v]=1;
		else if (v==1) toStart[u]=1;
	}
	
	vis[start] = 1;
	if (!p[start]) printf("0");
	else printf("%d",dfs(start,1));
}
