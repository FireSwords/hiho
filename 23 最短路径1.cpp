#include <iostream>
#include <cstdio>
#define N 1001
#define INF 2000
using namespace std;
 
int d[N][N];
int flag[N]={0}, s[N]={INF};

int main() {
	int i,j,n,m,start,end,p1,p2,len;
	scanf("%d%d%d%d",&n,&m,&start,&end);
	for (i=1; i<=n; ++i)
		for (j=1; j<=n; ++j)
			d[i][j] = INF;
	for (i=0; i<m; ++i) {
		scanf("%d%d%d",&p1,&p2,&len);
		if (len<d[p1][p2]) {
			d[p1][p2]=len;
			d[p2][p1]=len;
		}
	}	
	for (i=1; i<=n; ++i) {
		d[i][i] = 0;
		s[i] = d[start][i];
	}
	flag[start] = 1;
	
	int choose=0;
	while (choose!=end) {
		int ms=INF;
		for (i=1; i<=n; ++i) {
			if (!flag[i]&&(s[i]<ms)) {
				ms = s[i];
				choose = i;
			}
		}
		flag[choose] = 1;
		for (i=1; i<=n; ++i)
			if (!flag[i])
				s[i] = min(s[i], s[choose]+d[choose][i]);
	}
	printf("%d\n",s[end]);
}
