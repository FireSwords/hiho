#include <cstdio>
#include <iostream>
const int mod = 1e9+7;
const int N = 110;
int a[N][N], b[N][N], n, m;

void outputa() {
	int i,j;
	for (i=1; i<=n; ++i) {
		for (j=1; j<=n; ++j)
			printf("%d\t",a[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void outputb() {
	int i,j;
	for (i=1; i<=n; ++i) {
		for (j=1; j<=n; ++j)
			printf("%d\t",b[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

int findComm(int k, int m) {
	int a,b,c;
	a = (k>m) ? k:m;
	b = k + m - a;
	while (a%b) {
		c = a/b;
		c = a - b * c;
		a = (b>c) ? b:c;
		b = b + c - a;
	}
	return b;
}

int main() {
	int i,j,k;
	printf("%d\n",findComm(2,4));
	scanf("%d%d",&n,&m);
	
	for (i=1; i<=n; ++i) {
		int c = 1;
		for (j=1; j<=(i-1)>>1; ++j) {
			int tmp = 0;
			for (k=j; k<=(i-1)>>1; ++k)
				tmp = (tmp + b[i-k][k+1]) % mod;
			b[i][j] = (tmp + c) % mod;
		}
		for (j=((i-1)>>1)+1; j<=i; ++j)
			b[i][j] = c;
	}
	outputb();
	
	for (i=1; i<=n; ++i) {
		int c = (i%m==0) ? 1:0;
		for (j=1; j<=(i-1)>>1; ++j) {
			int tmp = 0;
			for (k=j; k<=(i-1)>>1; ++k) {
				int mm = findComm(k, m);
				mm = m/mm;
				if (k%mm==0) tmp = (tmp + b[i-k][k+1]) % mod;
				else tmp = (tmp + a[i-k][k+1]) % mod;
			}
			a[i][j] = (tmp + c) % mod;
		}
		for (j=((i-1)>>1)+1; j<=i; j++)
			a[i][j] = c;
	}
	outputa();
	printf("%d\n",a[n][1]);
	system("pause");
}
