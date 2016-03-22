#include <cstdio>
#include <malloc.h>
#include <string.h>

int max(int a, int b) {
	return a>b? a:b;
}

int main() {
	int n,m,q,i,j;
	scanf("%d%d%d",&n,&m,&q);
	int *w;
	w = (int*)malloc(sizeof(int)*n);
	for (i=0; i<n; ++i) 
		scanf("%d", &w[i]);
	
	int c = 1<<(m-1);
	int *best,*best0;
	best = (int*)malloc(sizeof(int)*c);
	best0 = (int*)malloc(sizeof(int)*c);
	memset(best0,0,sizeof(int)*c);
	int *sj = (int*)malloc(sizeof(int)*(c-1));
	sj[0]=0;
	for (j=1; j<(c>>1); ++j) 
		sj[j] = sj[j>>1]+(j&1);
	
	for (i=0; i<n; ++i) {
		for (j=0; j<(c>>1); ++j) {
			int newJ = j<<1;
			if (sj[j]<q-1)
				best[newJ+1] = max(best0[j], best0[(c>>1)+j])+w[i];
			else if (sj[j]==q-1)
				best[newJ+1] = best0[j]+w[i];
			if (sj[j]<q)
				best[newJ] = max(best0[j], best0[(c>>1)+j]);
			else
				best[newJ] = best0[j];
		}
		for (j=0; j<c; ++j)
			best0[j] = best[j];
	}
	
	int ans=0;
	for (j=0; j<c; ++j)
		if (best[j]>ans) ans=best[j];
	printf("%d\n", ans);
}
