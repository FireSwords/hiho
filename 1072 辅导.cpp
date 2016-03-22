#include <cstdio>
#include <cmath>

int const N = 1e9+7;
bool m[N];

void markMultiplier(int a) {
	for (int i=2; i<=(int)sqrt(a); ++i)
		if (a%i==0) m[i]=true;
}

int main() {
	int n,k,i;
	scanf("%d%d",&n,&k);
	m[2]=1; m[3]=1;
	for (i=4; i<=n; ++i)
		markMultiplier(i);
		
	int ans = 1;
	for (i=n; i>0; --i) {
		if (m[i])
			ans = (ans*i)%N;
	}
	printf("%d\n",ans);
}
