#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5;
int x[N],y[N];

int main() {
	int t,n,r,i,j;
	scanf("%d",&t);
	while (t--) {
		int i,j,ans=0,sum=0,aver=0;
		scanf("%d%d",&n,&r);
		for (i=0; i<n; ++i) {
			scanf("%d%d",&x[i],&y[i]);
			sum += y[i];
		}
		aver = sum/n;
		printf("init: sum=%d aver=%d\n",sum,aver);
		
		i = 0;
		while (i<n-1) {
			j = i+1;
			while (x[j]-x[i]<=r) {
				if (y[i]==aver) break;
				int s = y[i] + y[j];
				if (y[i]<aver) {
					y[i] = min(aver, y[i]+y[j]);
					y[j] = s - y[i];
				} else {
					y[i] = aver;
					y[j] = s - aver;
				}
				j++;
			}
			ans = max(ans, y[i]);
			sum = sum - y[i];
			aver = sum/(n-i-1);
			printf("%d: y[%d]=%d sum=%d aver=%d\n",i,i,y[i],sum,aver);
			i++;
		}
		ans = max(ans, y[n-1]);
		printf("%d\n",ans);
	}
}
