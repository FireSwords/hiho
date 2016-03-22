#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string.h>
using namespace std;

const int N = 1e4+1;
int gender[N];
map<int, set<int> > edge;

bool dfs(int u) {
	set<int> e = edge[u];
	set<int>::iterator it;
	for (it=e.begin(); it!=e.end(); ++it) {
		int v = *it;
		if (gender[u]==gender[v])
			return false;
		else if (gender[v]==-1) {
			gender[v] = 1-gender[u];
			bool flag = dfs(v);
			if (!flag) return false;
		}
	}
	return true;
}

int main() {
	int t,m,n,i,u,v;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		edge.clear();
		memset(gender,-1,sizeof(int)*(n+1));
		for (i=0; i<m; ++i) {
			scanf("%d%d",&u,&v);
			edge[u].insert(v);
			edge[v].insert(u);
		}
		
		bool flag = true;
		for (i=1; i<=n; ++i) {
			if (gender[i]!=-1) continue;
			gender[i] = 0;
			if (!dfs(i)) {flag=false; break;}
		}
		if (flag) printf("Correct\n");
		else printf("Wrong\n");
	}
}
