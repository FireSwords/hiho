#include <cstdio>
#include <cstring>

const int N = 105;

int main() {
	int t,a[N],n,m,i,j;
	scanf("%d",&t);
	while (t--) {
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for (i=1; i<=n; ++i)
			scanf("%d",&a[i]);
		a[n+1] = 100;
		
		if (m>=n) printf("100\n");
		else {
			int max = 0;
			for (i=0; i<=n-m; ++i) {
				j = i+m+1;
				if (a[j]-a[i]>max)
					max = a[j]-a[i];
			}
			printf("%d\n",max-1);
		}
	}
}
