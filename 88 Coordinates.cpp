#include <cstdio>
#include <cmath>

int dp[200],dq[200];

int f(int* d, int a) {
	int i,cnt=0;
	for (i=1; i<=sqrt(a); ++i) {
		if (a%i==0)
			d[cnt++] = i;
	}
	if (d[cnt-1]!=sqrt(a)) {
		for (i=0; i<cnt; ++i) {
			d[i+cnt] = a/d[cnt-i-1];
		}
		cnt = cnt<<1;
	} else {
		for (i=0; i<cnt-1; ++i) {
			d[i+cnt] = a/d[cnt-i-2];
		}
		cnt = (cnt<<1)-1;		
	}
	return cnt;
}

int main() {
	int p,q,i,j;
	scanf("%d%d",&p,&q);
	int lp = f(dp, p);
	int lq = f(dq, q);
	for (i=0; i<lp; ++i)
		for (j=0; j<lq; ++j)
			printf("%d %d\n",dp[i],dq[j]);
	return 0;
}
