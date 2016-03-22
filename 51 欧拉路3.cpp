#include <cstdio>

const int N = 1<<15;

struct Edge{
	int to;
	Edge* next;
};
Edge e[2*N],*p[N];
int n,vis[N],path[N];

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}
void graph() {
	int u,v;
	int num = 1<<n;
	for (u=0; u<num; ++u) {
		v = (u<<1) % num;
		addEdge(u,v);
		v++;
		addEdge(u,v);
	}
}

bool dfs(int cur, int cnt) {
	if (cnt>(1<<n)) return false;
	if (cur==1<<(n-1)) {
		if (cnt==(1<<n)) return true;
		if (cnt<(1<<n)) return false;
	}
	for (Edge* e=p[cur]; e; e=e->next) {
		int nxt = e->to;
		if (vis[nxt]) continue;
		vis[nxt] = 1;
		if (dfs(nxt, cnt+1)) {
			path[cnt] = nxt;
			return true;
		};
		vis[nxt] = 0;
	}
	return false;
}

int main() {
	int i;
	scanf("%d",&n);
	graph();
	path[0] = 0;
	vis[0] = 1;
	dfs(0,1);
	
	/*for (i=0; i<(1<<n); ++i) 
		printf("%d ",path[i]);
	putchar('\n');*/
	
	for (i=0; i<n; ++i)
		putchar('0');
	for (i=1; i<=(1<<n)-n; ++i)
		printf("%d",path[i]&1);
	putchar('\n');
	return 0;
}
