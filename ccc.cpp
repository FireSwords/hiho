#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
#define N 1001
#define INF 0x3f
using namespace std;
typedef pair<int,int> pii;

int d[N][N];
map<pii,int> info;

int main() {
	int i,j,k,n,m,u,v,dis;
	scanf("%d%d",&n,&m);
	memset(d, INF, N*N*sizeof(int));
	for (i=0; i<n-1; ++i) {
		scanf("%d%d%d",&u,&v,&dis);
		if (u>v) swap(u,v);
		info[pii(u,v)] = dis;
		d[u][v]=d[v][u]=dis;
	}	
	for (i=1; i<=n; ++i) {
		d[i][i] = 0;
	}
	
	for (k=1; k<=n; ++k)
		for (i=1; i<n; ++i) {
			if (i==k) continue; 
			for (j=i+1; j<=n; ++j) {
				if (j==k) continue;
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
				d[j][i] = d[i][j];
			}
		}	
	for (i=1; i<=n; ++i) {
		for (j=1; j<n; ++j)
			printf("%d ", d[i][j]);
		printf("%d\n", d[i][n]);
	}

	int ans=0;
	for (i=1; i<n; ++i) {
		for (j=i+1; j<=n; ++j)
			ans+=d[i][j];
	}
	char query[]="QUERY";
	string sq=query,op;
	while (m--) {
		cin>>op;
		if (op==sq) printf("%d\n",ans);
		else {
			scanf("%d%d%d",&u,&v,&dis);
			if (u>v) swap(u,v);
			ans += dis - info[pii(u,v)];
			info[pii(u,v)] = dis;
		}
	}
	return 0;
}
