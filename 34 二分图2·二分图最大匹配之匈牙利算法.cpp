#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int N = 1001;
const int M = 5000;

struct Edge {
	int tid;
	Edge *next;
};
Edge e[M<<1], *p[N]={NULL};
int match[N]={0}, mark[N]={0};

void addEdge(int u,int v) {
	static int cnt = 0;
	e[cnt].tid = v;
	e[cnt].next = p[u];
	p[u] = &e[cnt];
	++cnt;
}

bool path(int o) {
	Edge *e;
	for (e=p[o]; e!=NULL; e=e->next) {
		int to = e->tid;
		if (mark[to]) continue;
		mark[to] = 1;
		if (!match[to]||path(match[to])) {
			match[o] = to;
			match[to] = o;
			return true;
		}
	}
	return false;
}

int main() {
	int i,n,m,u,v;
	scanf("%d%d",&n,&m);
	for (i=0; i<m; ++i) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	
	int cnt = 0;
	for (i=1; i<=n; ++i) {
		if (match[i]) continue;
		memset(mark,0,sizeof(int)*(n+1));
		if (path(i)) cnt++;
	}
	printf("%d\n",cnt);
}
