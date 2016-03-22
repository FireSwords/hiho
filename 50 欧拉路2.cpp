#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

const int N = 1e3+1;
const int M = 5e3;
struct Edge {
	int to,*vis;
	Edge* next;
};
Edge e[2*M], *p[N];
int n,degree[N],vis[M];

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].vis = &vis[size>>1];
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

void dfs(int u) {
	for (Edge* e=p[u]; e; e=e->next) {
		if (*(e->vis)) continue;
		*(e->vis) = 1;
		dfs(e->to);
	}
	printf("%d ",u);
}

int findStart() {
	int i;
	for (i=1; i<=n; ++i) {
		Edge* e = p[i];
		while (e) {
			degree[e->to]++;
			e = e->next;
		}
	}
	
	for (i=1; i<=n; ++i) 
		if (degree[i]&1) return i;	
	for (i=1; i<=n; ++i)
		if (degree[i]) return i;
}

int main() {
	int m,k,i,u,v;
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	
	int start = findStart();
	dfs(start);
	printf("\n");
	return 0;
}
