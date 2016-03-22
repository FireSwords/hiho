#include <cstdio>
const int N = 1000;
const int INF = 0x3fffffff;

int a[N][N],len[N],vis[N]={0};

int main() {
	int i,j,n;
	scanf("%d",&n);
	for (i=0; i<n; ++i) 
		for (j=0; j<n; ++j)
			scanf("%d", &a[i][j]);
	
	int newv, ans=0;
	vis[0] = 1;
	for (i=0; i<n; ++i)
		len[i] = a[0][i];
	for (i=1; i<n; ++i) {
		int md=INF;
		for (j=0; j<n; ++j) {
			if ((!vis[j])&&(len[j]<md)) {
				md = len[j];
				newv = j;
			}
		}
		vis[newv] = 1;
		ans += md;
		for (j=0; j<n; ++j)
			if (a[newv][j]<len[j])
				len[j] = a[newv][j];
	}
	
	printf("%d\n",ans);
}
