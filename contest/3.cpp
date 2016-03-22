#include <cstdio>

const int N = 10;
const int M = 100;
int a[M], b[M];
int n,m,k,t;

int main() {
	int q,i,j;
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d%d%d",&n,&m,&k,&t);
		for (i=0; i<n; ++i)
			scanf("%d",&a[i]);
		for (i=0; i<n; ++i) 
			scanf("%d",&b[i]);
		unsigned long long ans = 0;
		int flag = 0;
		for (i=0; i<n; ++i) {
			int min=0x3fffffff;
			flag = 0;
			for (j=0; j<m; ++j) {
				if (b[j]==0) continue;
				int cost = (k+b[j]-1)/b[j]*a[j];
				if (cost<min) {
					min = cost;
					flag = 1;
				}
			}
			if (flag) ans+=min;
			else break;
			for (j=0; j<m; ++j)
				b[j] = b[j]/t;
		} 		
		if (flag) printf("%lld\n",ans);
		else printf("No Answer\n");
	}
	return 0;
}
