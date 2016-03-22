#include <iostream>
#include <cstdio>
#include <string.h>
#define N 101
#define INF 100010
using namespace std;
 
int d[N][N];

int main() {
	int i,j,k,n,m,p1,p2,len;
	scanf("%d%d",&n,&m);
	memset(d, INF, N*N*sizeof(int));
	for (i=0; i<m; ++i) {
		scanf("%d%d%d",&p1,&p2,&len);
		if (len<d[p1][p2])
			d[p1][p2]=d[p2][p1]=len;
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
	return 0;
}
