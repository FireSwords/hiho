#include <cstdio>
#include <cstring>

const int M = 128;
const int mod = 12357;
int n,k,state;
int mat[M][M],newmat[M][M],s[M],news[M];

void dfs(int x,int y,int col) {
	if (col==k) {
		mat[y][x] = 1; 
		return;
	}
	dfs(x<<1, (y<<1)+1, col+1);
	dfs((x<<1)+1, y<<1, col+1);
	if (col + 2 <= k)
		dfs((x<<2)+3, (y<<2)+3, col+2);
}

void mat2() {
	int i,j,k;
	for (i=0; i<state; ++i)
		for (j=0; j<state; ++j) {
			int sum = 0;
			for (k=0; k<state; ++k) {
				sum += mat[i][k]*mat[k][j];
				if (sum>mod) sum = sum % mod;
			}
			newmat[i][j] = sum;
		}
	memcpy(mat,newmat,sizeof(mat));
}

void vec_mul_mat() {
	int j,k;
	for (j=0; j<state; ++j) {
		int sum = 0;
		for (k=0; k<state; ++k) {
			sum += s[k]*mat[k][j];
			if (sum>mod) sum = sum % mod;
		}
		news[j] = sum;
	}
	memcpy(s,news,sizeof(s));
}

int main() {
	scanf("%d%d",&k,&n);
	if ((k&1)&&(n&1)) {
		printf("0\n");
		return 0;
	}
	
	state = 1<<k;
	dfs(0,0,0);
	s[state-1] = 1;
	while(n) {
		if (n&1) vec_mul_mat();
		mat2();
		n = n>>1;
	}
	printf("%d\n",s[state-1]);
	return 0;
}


