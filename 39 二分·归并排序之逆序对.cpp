#include <stdio.h>
const int N = 1e5;
int a[N],b[N];

long conquer(int l,int r) {
	if (l==r) return 0;
	long cnt = 0;
	int m = (l+r)>>1;
	cnt += conquer(l,m);
	cnt += conquer(m+1,r);
		
	int pl=l, pr=m+1, pos=l, i;
	while(pl<=m||pr<=r) {
		while (pl<=m && (pr>r || a[pl]<=a[pr])) {
			b[pos++] = a[pl++]; 
			cnt += pr-(m+1);
		} 
		while (pr<=r && (pl>m || a[pl]>a[pr])) {
			b[pos++] = a[pr++];
		}
	}
	for (i=l; i<=r; ++i) a[i]=b[i];
	return cnt;
}

int main() {
	int n,i,j;
	scanf("%d",&n);
	for (i=0; i<n; ++i)
		scanf("%d",&a[i]);
	printf("%ld\n",conquer(0,n-1));
	return 0;
}
