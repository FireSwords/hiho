#include <cstdio>

int dfs(int n, int p) {
	if (n>p || n*6<p)
		return 0;
	if (n==1 && p>=1 && p<=6)
		return 1;
	int i, cnt=0, a;
	for (i=1; i<=6; ++i) {
		a = dfs(n-1, p-i);
		//printf("n=%d, p=%d, a=%d\n",n,p,a);
		cnt += a;
	}
	return cnt;
}

int main() {
	int n,p;
	scanf("%d%d",&n,&p);
	printf("%d\n", dfs(n,p));
}
