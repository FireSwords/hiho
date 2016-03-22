#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

const int N = 1e4+1;
const int M = 1e5;

struct Edge{
	int to,w;
	Edge* next;
};
Edge e[M*2], *p[N]={NULL};
int vis[N];
int n,t,k;

void addEdge(int u, int v, int w) {
	static int i = 0;
	e[i].to = v;
	e[i].w = w;
	e[i].next = p[u];
	p[u] = &e[i];
	i++;
}

bool f(int x) {
	memset(vis,0,sizeof(int)*(n+1));
	queue<int> h;
	h.push(1);
	while(!h.empty()) {
		int o = h.front(); h.pop();
		if (o==t) return true;
		if (vis[o]==k) continue;
		for (Edge* e=p[o]; e; e=e->next) {
			int to = e->to;
			if (vis[to]||e->w>x) continue;
			vis[to] = vis[o] + 1;
			h.push(to);
		}
	}
	return false;
}

int conquer(int l,int r) {
	if (l==r-1) return r;
	int m = (l+r)>>1;
	if (f(m)) return conquer(l,m);
	else return conquer(m,r);
}

int main() {	
	int m,i,u,v,w,max_w=1;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for (i=0; i<m; ++i) {
		scanf("%d%d%d",&u,&v,&w);
		addEdge(u,v,w);
		addEdge(v,u,w);
		if (w>max_w) max_w=w;
	}
	printf("%d\n", conquer(0,max_w));
}
