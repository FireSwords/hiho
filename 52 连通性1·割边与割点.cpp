#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

const int N = 2e4+1;
const int M = 1e5;
struct Edge {
	int to;
	Edge* next;
};
Edge e[2*M], *p[N];
int n,d;
int dfn[N],low[N],vis[N];
int cutPoint[N],root=1,cnt=0;
pii cutEdge[M];

void addEdge(int u,int v) {
	static int size = 0;
	e[size].to = v;
	e[size].next = p[u];
	p[u] = &e[size];
	size++;
}

int dfs(int pre,int cur) {
	int treeCnt = 0;
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
		treeCnt++;
		vis[nxt] = 1;
		dfs(cur, nxt);
		low[cur] = min(low[cur], low[nxt]);
		//printf("cur=%d, low[%d]=%d\n",cur,cur,low[cur]);
	}
	return treeCnt;
}


void search(int cur) {
	for (Edge* e=p[cur]; e; e=e->next) {
		int nxt = e->to;
		if (vis[nxt]) continue;
		if (low[nxt]>=dfn[cur]) {
			if (cur!=root) cutPoint[cur] = 1;
			if (low[nxt]>dfn[cur]) {
				int a,b;
				if (cur>nxt) {a=nxt; b=cur;}
				else {a=cur; b=nxt;}
				cutEdge[cnt].first = a;
				cutEdge[cnt].second = b;
				cnt++;
			}
		}
		vis[nxt] = 1;
		search(nxt);
	}
}

int cmp(pii e1,pii e2) {
	if (e1.first<e2.first) return 1;
	if (e1.first>e2.first) return 0;
	if (e1.second<e2.second) return 1;
	return 0;
}

int main() {
	int m,u,v,i;
	scanf("%d%d",&n,&m);
	while (m--) {
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
	}
	
	/*** 以下用dfs计算dfn和low数组 ***/
	memset(vis,0,sizeof(int)*(n+1));
	memset(low,0x3f,sizeof(int)*(n+1));
	vis[root] = 1;
	int treeCnt = dfs(-1, root);

	
	/*** 以下计算割点与割边 ***/
	memset(vis,0,sizeof(int)*(n+1));
	memset(cutPoint,0,sizeof(int)*(n+1));
	cnt = 0;
	if (treeCnt>1) cutPoint[root]=1;
	vis[root] = 1;
	search(root);
	
	/*** 以下查看dfn和low数组结果 ***/ 
	/*printf("%d\n",treeCnt);
	for (i=1; i<=n; ++i)
		printf("%d ",dfn[i]);
	putchar('\n');
	for (i=1; i<=n; ++i)
		printf("%d ",low[i]);
	putchar('\n');*/
	
	/*** 以下用输出最终结果 ***/
	bool flag = false;
	for (i=1; i<=n; ++i)
		if (cutPoint[i]) {
			printf("%d ",i);
			flag = true;
		}
	if (!flag) printf("Null");
	putchar('\n');
	if (cnt) {
		sort(cutEdge,cutEdge+cnt,cmp);
		for (i=0; i<cnt; ++i)
			printf("%d %d\n",cutEdge[i].first,cutEdge[i].second);
	}
}
