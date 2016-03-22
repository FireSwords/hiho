#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6;
int a[N];

int conquer(int l, int r, int k) {
	int key = a[l];
	int i=l, j=r;
	while (i<j) {
		while (i<j && a[j]>=key) j--;
		a[i] = a[j];
		while (i<j && a[i]<=key) i++;
		a[j] = a[i];
	}
	a[i] = key;
	
	if (k==i) return a[k];
	else if (k<i) return conquer(l,i-1,k);
	else return conquer(i+1,r,k);
}

int main() {
	int n,k,i;
	scanf("%d%d",&n,&k);
	for (i=0; i<n; ++i)
		scanf("%d",&a[i]);
	if (k<0||k>n) printf("-1\n");
	else printf("%d\n", conquer(0,n-1,k-1));
}
