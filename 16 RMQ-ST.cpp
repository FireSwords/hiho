#include <iostream>
#include <cstdio>
#include <cmath>
#define N 1000010
using namespace std;

int v[N][20]={10000};

int main() {
	int i,j,n,q;
	cin>>n;
	for (i=1; i<=n; ++i)
		scanf("%d",&v[i][0]);
	int k=log2(n);
	for (j=1; j<=k; ++j) {
		for (i=1; i<=n-(1<<j)+1; ++i) {
			v[i][j] = min(v[i][j-1], v[i+(1<<(j-1))][j-1]);
		}
	}
	
	int l,r;
	scanf("%d",&q);
	for (i=0; i<q; ++i) {
		scanf("%d%d",&l,&r);
		k = log2(r-l+1);
		printf("%d\n", min(v[l][k], v[r-(1<<k)+1][k]));
	}
}

