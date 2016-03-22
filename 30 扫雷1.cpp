#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5+1;
int a[N],x0[N],x1[N],n;

bool solve(int *x, int assume) {
	int i;
	x[0] = 0;
	x[1] = assume;
	for (i=2; i<=n; ++i) {
		x[i] = a[i-1] - x[i-1] - x[i-2];
		if (x[i]<0||x[i]>1) return false;
	}
	if (x[n-1]+x[n]==a[n]) return true;
	return false;
}

void output(int *x) {
	int yes[N],no[N],cy=0,cn=0,i;
	for (i=1; i<=n; ++i)
		if (x[i]==1)
			yes[cy++] = i;
		else if (x[i]==0)
			no[cn++] = i;
			
	printf("%d",cy);
	for (i=0; i<cy; ++i)
		printf(" %d",yes[i]);
	putchar('\n');
	
	printf("%d",cn);
	for (i=0; i<cn; ++i)
		printf(" %d",no[i]);
	putchar('\n');
}

int main() {
	int task,i;
	bool flag0,flag1;
	scanf("%d",&task);
	while(task--) {
		scanf("%d",&n);
		for (i=1; i<=n; ++i)
			scanf("%d",&a[i]);
		flag0 = solve(x0, 0);
		flag1 = solve(x1, 1);
		if (flag0&&flag1) {
			for (i=1; i<=n; ++i)
				if (x0[i]!=x1[i])
					x0[i] = -1;
			output(x0);
		}
		else if (flag0)
			output(x0);
		else if (flag1)
			output(x1);
	}
}
