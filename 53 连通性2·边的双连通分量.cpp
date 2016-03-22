#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 2e4+1;
const int M = 1e5;
struct Edge {
	int to;
	Edge* next;
};
Edge e[2*M], *p[N];
int n,d;
int dfn[N],low[N],vis[N],root=1;
int rep[N],group[N],groupCnt=0;
stack<int> h;

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

void dfs(int pre,int cur) {
	h.push(cur);
	dfn[cur] = ++d; low[cur] = d;
	//printf("cur=%d, dfn[%d]=%d\n",cur,cur,dfn[cur]);
	for (Edge* e=p[cur]; e; e=e->next) {
		int nxt = e->to;
		if (vis[nxt]) {
			if (nxt!=pre) {
				low[cur] = min(low[cur], dfn[nxt]);
				//printf("cur=%d, low[%d]=%d\n",cur,cur,low[cur]);
			}
			continue;
		}
		vis[nxt] = 1;
		dfs(cur, nxt);
		low[cur] = min(low[cur], low[nxt]);
		//printf("cur=%d, low[%d]=%d\n",cur,cur,low[cur]);
	}
	
	if (low[cur]==dfn[cur]) {
		int c=0, a;
		do {
			a=h.top(); h.pop();
			group[c++] = a;
		} while(a!=cur);
		sort(group,group+c);
		int r = group[0];
		rep[group[0]] = r;
		for (int i=1; i<c; ++i)
			rep[group[i]] = r;
		groupCnt++;
	}
}

int main() {
	int m,u,v,i;
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	memset(vis,0,sizeof(int)*(n+1));
	memset(low,0x3f,sizeof(int)*(n+1));
	memset(rep,0,sizeof(int)*(n+1));
	
	/*** 以下用dfs计算dfn和low数组 ***/
	vis[root] = 1;
	dfs(-1, root);
	
	/*** 以下查看dfn和low数组结果 ***/ 
	/*printf("%d\n",treeCnt);
	for (i=1; i<=n; ++i)
		printf("%d ",dfn[i]);
	putchar('\n');
	for (i=1; i<=n; ++i)
		printf("%d ",low[i]);
	putchar('\n');*/
	
	/*** 以下用输出最终结果 ***/
	printf("%d\n",groupCnt);
	for (i=1; i<=n; ++i)
		printf("%d ",rep[i]);
	putchar('\n');
}
