#include <cstdio>
#define N 100

int a[N][N];

int max(int a, int b) {
	return a>b? a:b;
}

int main() {
	char n,i,j;
	scanf("%d", &n);
	for (i=0; i<n; ++i) 
		for (j=0; j<=i; ++j)
			scanf("%d", &a[i][j]);
	
	for (i=n-1; i>0; --i)
		for (j=0; j<i; ++j)
			a[i-1][j] += max(a[i][j], a[i][j+1]);
	
	printf("%d\n", a[0][0]);
} 
