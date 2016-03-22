#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 60;
float a[N];
int b[N],n;

int dfs(int si, float w, int v,int d) {
	if ((d==0)||(si>=n))  {
		if ((abs(w-(int)w)<1e-6)&&((int)w%5<1e-6)) return v;
		else return 0;
	}
	return std::max(dfs(si+1,w,v,d), dfs(si+1,w+a[si],v+b[si],d-1));
}

int main() {
	int q,i,j;
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&n);
		for (i=0; i<n; i++)
			scanf("%f %d",&a[i],&b[i]);
		printf("%d\n", dfs(0,0.0,0,3));
	}
}
