#include <cstdio>

const int N = 210;
char map[N][N],pos[8][9];
int n,m;

void rotate(char *cur, char *nxt) {
	nxt[0] = cur[3];	nxt[1] = cur[0];	nxt[2] = cur[1];
	nxt[3] = cur[6];	nxt[4] = cur[4];	nxt[5] = cur[2];
	nxt[6] = cur[7];	nxt[7] = cur[8];	nxt[8] = cur[5];
}

bool match(int i,int j) {
	for (int k=0; k<8; ++k) {
		if (map[i-1][j-1] != pos[k][0]) continue;
		if (map[i-1][j  ] != pos[k][1]) continue;
		if (map[i-1][j+1] != pos[k][2]) continue;
		if (map[i  ][j-1] != pos[k][3]) continue;
		if (map[i  ][j  ] != pos[k][4]) continue;
		if (map[i  ][j+1] != pos[k][5]) continue;
		if (map[i+1][j-1] != pos[k][6]) continue;
		if (map[i+1][j  ] != pos[k][7]) continue;
		if (map[i+1][j+1] != pos[k][8]) continue;
		return true;
	}
	return false;
}

int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=0; i<n; ++i)
		scanf("%s",map[i]);
	for (i=0; i<3; ++i) {
		char tmp[20];
		int base = i*3;
		scanf("%s",tmp);
		pos[0][base]=tmp[0]; 
		pos[0][base+1]=tmp[1];
		pos[0][base+2]=tmp[2];
	}
	for (i=1; i<8; ++i)
		rotate(pos[i-1], pos[i]);
	
	for (i=1; i<n-1; ++i)
		for (j=1; j<m-1; ++j)
			if (match(i,j)) printf("%d %d\n",i+1,j+1);
}
