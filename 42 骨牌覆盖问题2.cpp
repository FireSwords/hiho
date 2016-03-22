#include <cstdio>

const int mod = 12357;

int main() {
	int n;
	scanf("%d", &n);
	if (n&1) {
		printf("0\n");
		return 0;
	}
	
	int a=1, b=3, i;
	n = (n-2)/2;
	long long mat[4]={0,-1,1,4}, newmat[4];
	while (n) {
		if (n&1) {
			int ta = (a*mat[0] + b*mat[2]) % mod;
			int tb = (a*mat[1] + b*mat[3]) % mod;
			if (ta<0) ta+=mod;
			if (tb<0) tb+=mod;
			a=ta; b=tb;
		}
		//printf("%d %d %d %d %d %d\n",mat[0],mat[1],mat[2],mat[3],a,b);
		newmat[0] = (mat[0]*mat[0])%mod + (mat[1]*mat[2])%mod;
		newmat[1] = (mat[0]*mat[1])%mod + (mat[1]*mat[3])%mod;
		newmat[2] = (mat[2]*mat[0])%mod + (mat[3]*mat[2])%mod;
		newmat[3] = (mat[2]*mat[1])%mod + (mat[3]*mat[3])%mod;
		for (i=0; i<4; ++i) {
			mat[i] = newmat[i];
			if (mat[i]<0) mat[i]+=mod;
		}
		n = n>>1;
	}
	printf("%d\n",b);
	return 0;
}
