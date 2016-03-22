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
int n,degree[N],size;

void addEdge(int u,int v) {
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

bool check() {
	queue<int> h;
	int i,cur,nxt;
	
	for (i=1; i<=n; ++i)
		if (!degree[i])	h.push(i);	
	while(!h.empty()) {
		cur=h.front(); h.pop();
		for (Edge* e=p[cur]; e; e=e->next) {
			int nxt = e->to;
			degree[nxt]--;
			if (!degree[nxt]) 
				h.push(nxt);
		}
	}
	for (i=1; i<=n; ++i)
		if (degree[i]) return false;
	return true;
}

int main() {
	int t,m,i,u,v;
	scanf("%d",&t);
	while (t--) {
		size = 0;
		memset(e,(-1,NULL),sizeof(e));
		memset(p,NULL,sizeof(p));
		memset(degree,0,sizeof(degree));
		
		scanf("%d%d",&n,&m);
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
		if (check()) printf("Correct\n");
		else printf("Wrong\n");
	}
}
