#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

int add(int x, int y) {
	return (x+y)%mod;
}

int f3(int n) {
	int *f = (int*)malloc(sizeof(int)*(n+1));
	int *g = (int*)malloc(sizeof(int)*n);
	g[1]=1; g[2]=0; 
	f[2]=3;
	int i;
	for (i=4; i<=n; i+=2) {
		g[i-1] = add(f[i-2],g[i-3]);
		f[i] = add(add(f[i-2],g[i-1]),g[i-1]);
	}
	return f[n];
}

int f4(int n) {
	int *f = (int*)malloc(sizeof(int)*(n+1));
	int *g1 = (int*)malloc(sizeof(int)*n);
	int *g2 = (int*)malloc(sizeof(int)*n);
	g1[1]=1; g2[0]=0; g2[1]=1;
	f[1]=1; f[2]=5;
	int i;
	for (i=3; i<=n; ++i) {
		g1[i-1] = add(f[i-2],g1[i-2]);
		g2[i-1] = add(f[i-2],g2[i-3]);
		f[i] = add(add(add(add(f[i-1],f[i-2]),g1[i-1]),g1[i-1]),g2[i-1]); 
	}
	return f[n];	
}

int f5(int n) {
	int *f = (int*)malloc(sizeof(int)*(n+1));
	int *g1 = (int*)malloc(sizeof(int)*n);
	int *g2 = (int*)malloc(sizeof(int)*n);
	int *g3 = (int*)malloc(sizeof(int)*n);
	int *g4 = (int*)malloc(sizeof(int)*n);
	g1[1]=1; g2[1]=1; g3[1]=1; g4[1]=1;
	f[2]=8;
	int i;
	for (i=4; i<=n; i+=2) {
		g1[i-1] = add(add(add(f[i-2],g1[i-3]),g3[i-3]),g4[i-3]); 
		g2[i-1] = add(add(f[i-2],g2[i-3]),g3[i-3]);
		g3[i-1] = add(add(add(add(add(add(f[i-2],g1[i-3]),g2[i-3]),g3[i-3]),g3[i-3]),g3[i-3]),g4[i-3]);
		g4[i-1] = add(add(add(add(add(f[i-2],g1[i-3]),g1[i-3]),g3[i-3]),g3[i-3]),g4[i-3]);
		f[i] = add(add(add(add(add(add(add(f[i-2],g1[i-1]),g1[i-1]),g2[i-1]),g2[i-1]),g3[i-1]),g3[i-1]),g4[i-1]);
	}
	return f[n];	
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if ((n&1)&&(m&1)) printf("0\n");
	else if (m==3) printf("%d\n", f3(n));
	else if (m==4) printf("%d\n", f4(n));
	else if (m==5) printf("%d\n", f5(n));
	return 0;
}
