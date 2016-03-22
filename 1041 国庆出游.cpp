#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 105;
struct edge {
	int to,*vis;
	edge *next;
};
edge *p[N];
int level[N],vis[N];
queue<int> forbid;

void addEdge(int u,int v) {
	static int size = 0;
	edge *e = new edge();
	e->to = v;
	e->next = p[u];
	e->vis = &vis[size>>1];
	p[u] = e;
	size++;
}

void setLevel(int u,int l) {
	level[u] = l;
	for (edge* e=p[u]; e; e=e->next) {
		int v = e->to;
		if (level[v]) continue;
		setLevel(v, l+1);
	}
}
 
bool travel(int u,int v) {
	if (u==v) return true;
	for (edge* e=p[v]; e; e=e->next) {
		if (level[e->to]>=level[v]) continue;
		int father = e->to;
		queue<int> tmp(forbid);
		while (!tmp.empty()) {
			int a=tmp.front(); tmp.pop();
			if (a==father) return false;
		}
		if (*(e->vis)>=2) return false;
		*(e->vis) += 1;
		//printf("u=%d v=%d vis=%d\n",father,v,*(e->vis));
		if (level[father]<level[u]) return travel(father, u);
		else return travel(u, father);
	}
}

int main() {
	int i,t,n,m,u,v;
	scanf("%d",&t);
	while (t--) {
		memset(p,NULL,sizeof(p));
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for (i=1; i<=n-1; ++i) {
			scanf("%d%d",&u,&v);
			addEdge(u,v);
			addEdge(v,u);
		}
		setLevel(1, 1);
		
		scanf("%d",&m);
		while (m--) {
			scanf("%d",&v);
			forbid.push(v);
		}
		
		bool flag = true;
		u = 1;
		while (!forbid.empty()) {
			v=forbid.front(); forbid.pop();
			if (flag) {
				if (level[u]<=level[v]) flag=travel(u,v);
				else flag=travel(v,u);
			}
			u = v;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
}
