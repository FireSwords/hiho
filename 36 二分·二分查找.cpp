#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6;
int a[N];

int conquer(int l, int r, int k) {
	if (l==r&&k!=a[l]) return -1;

	int key = a[l];
	int i=l, j=r;
	while (i<j) {
		while (i<j && a[j]>=key) j--;
		a[i] = a[j];
		while (i<j && a[i]<=key) i++;
		a[j] = a[i];
	}
	a[i] = key;
	
	if (k==key) return i;
	else if (k<key) return conquer(l,i-1,k);
	else return conquer(i+1,r,k);
}

int main() {
	int n,k,i;
	scanf("%d%d",&n,&k);
	for (i=0; i<n; ++i)
		scanf("%d",&a[i]);
	printf("%d\n", conquer(0,n-1,k)+1);
}
