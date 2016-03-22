#include <cstdio>
#include <malloc.h>
#include <string.h>

int max(int a, int b) {
	return a>b? a:b;
}

int main() {
	int n,m,i,j;
	int *need,*value,*best;
	scanf("%d%d",&n,&m);
	need = (int*)malloc(sizeof(int)*n);
	value = (int*)malloc(sizeof(int)*n);
	for (i=0; i<n; ++i) 
		scanf("%d%d", &need[i], &value[i]);
	
	best = (int*)malloc(sizeof(int)*(m+1));
	memset(best,0,sizeof(int)*(m+1));
	for (i=0; i<n; ++i) 
		for (j=need[i]; j<=m; ++j) 
			best[j] = max(best[j-need[i]]+value[i], best[j]);
	
	printf("%d\n", best[m]);
}
