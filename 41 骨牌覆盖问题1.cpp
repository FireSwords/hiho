#include <cstdio>
const int mod = 19999997;
int main() {
////while(1) {
	int i,n;
	long long mat[4]={0,1,1,1}, newmat[4];
	scanf("%d",&n);
	int a=1,b=1;
	n--;
	while (n) {
		if (n&1) {
			int ta = (a*mat[0] + b*mat[2]) % mod;
			int tb = (a*mat[1] + b*mat[3]) % mod;
			a=ta; b=tb;
		}
		//printf("%d %d %d %d %d %d\n",mat[0],mat[1],mat[2],mat[3],a,b);
		newmat[0] = (mat[0]*mat[0])%mod + (mat[1]*mat[2])%mod;
		newmat[1] = (mat[0]*mat[1])%mod + (mat[1]*mat[3])%mod;
		newmat[2] = (mat[2]*mat[0])%mod + (mat[3]*mat[2])%mod;
		newmat[3] = (mat[2]*mat[1])%mod + (mat[3]*mat[3])%mod;
		for (i=0; i<4; ++i)
			mat[i] = newmat[i];
		n = n>>1;
	}
	printf("%d\n",b);
//}
} 
