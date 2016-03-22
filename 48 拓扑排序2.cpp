#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5+1;
const int M = 5e5;
const int mod = 142857;
struct Edge {
	int to;
	Edge* next;
};
Edge e[M], *p[N];
int n,virus[N],degree[N];

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

void broadcast() {
	queue<int> h;
	int i,cur,nxt;
	
	for (i=1; i<=n; ++i)
		if (!degree[i])	h.push(i);
			
	while(!h.empty()) {
		cur=h.front(); h.pop();
		for (Edge* e=p[cur]; e; e=e->next) {
			int nxt = e->to;
			virus[nxt] += virus[cur];
			if (virus[nxt]>mod) virus[nxt]=virus[nxt]%mod;
			degree[nxt]--;
			if (!degree[nxt]) h.push(nxt);
		}
	}
}

int main() {
	int m,k,i,u,v;
	scanf("%d%d%d",&n,&m,&k);
	while (k--) {
		scanf("%d",&u);
		virus[u] = 1;
	}
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
	}
	
	for (i=1; i<=n; ++i) {
		Edge* e = p[i];
		while (e) {
			degree[e->to]++;
			e = e->next;
		}
	}
	broadcast();
	
	int cnt = 0;
	for (i=1; i<=n; ++i) {
		cnt += virus[i];
		if (cnt>mod) cnt=cnt%mod;
	}
	printf("%d\n",cnt);
}
