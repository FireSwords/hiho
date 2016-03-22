#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5+1;
const int M = 5e5;
struct Edge {
	int to;
	Edge* next;
};
Edge e[M], *p[N];
int n,vis[M],degree[N];

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

bool checkCon() {
	queue<int> h;
	int i,cur,nxt;
	h.push(1);
	vis[1]=1;
	while(!h.empty()) {
		cur=h.front(); h.pop();
		for (Edge* e=p[cur]; e; e=e->next) {
			int nxt = e->to;
			if (vis[nxt]) continue;
			h.push(nxt);
			vis[nxt] = 1;
		}
	}
	
	for (i=1; i<=n; ++i)
		if (!vis[i]&&degree[i]>0) return false;
	return true;
}

bool checkDeg() {
	int i,odd=0;
	for (i=1; i<=n; ++i) {
		Edge* e = p[i];
		while (e) {
			degree[e->to]++;
			e = e->next;
		}
	}
	for (i=1; i<=n; ++i) 
		if (degree[i]&1) odd++;
	
	if (odd>2) return false;
	else return true;
}

int main() {
	int m,k,i,u,v;
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	printf("%d %d\n",checkCon(),checkDeg());
	//if (checkDeg()&&checkCon())
	//	printf("Full\n");
	//else printf("Part\n");
}
