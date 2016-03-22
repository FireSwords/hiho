#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
typedef pair<int,int> pii;

const int N = 2e4+1;
const int M = 1e5;

struct Edge {
	int to,vis;
	Edge* next;
	Edge(int v, Edge* p) {to=v; vis=0; next=p;}
};
Edge *p[N];
int w[N],n,d=0,size=0;
int low[N],dfn[N],vis[N],instack[N];
int rep[N],group[N];
stack<int> h;

void addEdge(int u,int v) {
	Edge *e = new Edge(v, p[u]);
	p[u] = e;
	size++;
}

void dfs(int cur) {
	h.push(cur); instack[cur]=1;
	dfn[cur] = ++d; low[cur] = d;
	//printf("cur=%d, dfn[%d]=%d\n",cur,cur,dfn[cur]);
	for (Edge* e=p[cur]; e; e=e->next) {
		int nxt = e->to;
		if (vis[nxt]) {
			if (instack[nxt]) {
				low[cur] = min(low[cur], dfn[nxt]);
				//printf("cur=%d, low[%d]=%d\n",cur,cur,low[cur]);
			}
			continue;
		}
		vis[nxt] = 1;
		dfs(nxt);
		low[cur] = min(low[cur], low[nxt]);
		//printf("cur=%d, low[%d]=%d\n",cur,cur,low[cur]);
	}
	
	if (low[cur]==dfn[cur]) {
		int c=0, a;
		do {
			a=h.top(); 
			h.pop(); instack[a]=0;
			group[c++] = a;
		} while(a!=cur);
		sort(group,group+c);
		int r0 = group[0];
		rep[r0] = r0;
		for (int i=1; i<c; ++i) {
			int ri = group[i];
			rep[ri] = r0;
			w[r0] += w[ri];
		}
	}
}

long long grass(int cur) {
	long long v = 0;
	for (Edge* e=p[cur]; e; e=e->next) {
		int nxt = e->to;
		v = max(v, grass(nxt));
	}
	return v + w[cur];
}

int main() {
	int i,m,u,v;
	set<pii> e0,e1;
	set<pii>::iterator it;
	scanf("%d%d",&n,&m);
	for (i=1; i<=n; ++i)
		scanf("%d",&w[i]);
	for (i=1; i<=m; ++i) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		e0.insert(pii(u,v));
	}
	
	int root = 1;
	vis[root] = 1;
	dfs(root);
	
	size = 0;
	for (i=1; i<=n; ++i) free(p[i]);
	memset(p,NULL,sizeof(p));
	for (it=e0.begin(); it!=e0.end(); ++it) {
		u = (*it).first; v = (*it).second;
		u = rep[u]; v = rep[v];
		if (u!=v) e1.insert(pii(u,v));
	}
	for (it=e1.begin(); it!=e1.end(); ++it) {
		u = (*it).first; v = (*it).second;
		addEdge(u,v);		
	}
	
	printf("%lld",grass(1));
}
