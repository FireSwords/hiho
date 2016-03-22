#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 500;
const int M = 2*N;
int n,m,bufsize;
float a[M][N],c[M],atmp[N],ctmp,ans[N];

int Gauss(int row, int col) {
	if (col==n) return row;
	int i,j;
	do {
		i = row;
		while (i<m && fabs(a[i][col])<1e-6) i++;
		if (i==m) col++;
		if (col==n) return row;
	} while(i==m);
	if (i>row) {
		memcpy(atmp,a[i],bufsize);
		memcpy(a[i],a[row],bufsize);
		memcpy(a[row],atmp,bufsize);
		ctmp=c[i]; c[i]=c[row]; c[row]=ctmp;
	}
	
	c[row] /= a[row][col];
	for (j=n-1; j>=col; --j)
		a[row][j] /= a[row][col];
	for (i=row+1; i<m; ++i) {
		c[i] -= a[i][col]*c[row];
		for (j=n-1; j>=col; --j)
			a[i][j] -= a[i][col]*a[row][j];
	}
	Gauss(row+1,col+1);
}

int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=0; i<m; ++i) {
		for (j=0; j<n; ++j)
			scanf("%lf",&a[i][j]);
		scanf("%lf",&c[i]);
	}
	bufsize = sizeof(float)*n;
	int ra = Gauss(0,0);
	int rc = (n+1)<m ? n+1:m;
	while (rc>0 && fabs(c[rc-1])<1e-6) rc--;
	
	/*printf("ra=%d rc=%d\n",ra,rc);
	for (i=0; i<m; ++i) {
		for (j=0; j<n; ++j)
			printf("%.3f ",a[i][j]);
		printf("%.3f\n",c[i]);
	}	*/
	
	if (rc==ra && ra<n) puts("Many solutions");
	else if (rc>ra) puts("No solutions");
	else {
		for (i=n-1; i>=0; --i) {
			ans[i] = c[i];
			for (j=n-1; j>i; --j)
				ans[i] -= ans[j]*a[i][j];
		}
		for (i=0; i<n; ++i)
			printf("%d\n",(int)(ans[i]+0.5));
	}
}
