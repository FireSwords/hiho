#include <cstdio>
#include <cstring>

const int row = 5;
const int col = 6;
const int size = row*col;
char a[size][size],c[size],x[size];
char atmp[size],ctmp;

void show() {
	int i,j;
	for (i=0; i<size; ++i) {
		for (j=0; j<size; ++j)
			printf(" %d",a[i][j]);
		printf("\t%d\n",c[i]);
	}
	printf("=========================================\n");
}

void Gauss(int r) {
	if (r==size) return;
	char i=r, j;
	while (!a[i][r]) ++i;
	if (i>r) {
		memcpy(atmp,a[i],size);
		memcpy(a[i],a[r],size);
		memcpy(a[r],atmp,size);
		ctmp=c[i]; c[i]=c[r]; c[r]=ctmp;
	}
	for (i=r+1; i<size; ++i) {
		if (!a[i][r]) continue;
		for (j=r; j<size; ++j)
			a[i][j] ^= a[r][j];
		c[i] ^= c[r];
	}
	//show();
	Gauss(r+1);
}

int main() {
	char i,j,pos;
	for (i=0; i<row; ++i) 
		for (j=0; j<col; ++j) {
			pos = i * col + j;
			a[pos][pos] = 1;
			if (i>0) a[pos][pos-col] = 1;
			if (i<row-1) a[pos][pos+col] = 1;
			if (j>0) a[pos][pos-1] = 1;
			if (j<col-1) a[pos][pos+1] = 1;
		}	
	int cnt = 0;
	while (cnt<size) {
		char ch = getchar();
		if (ch!='0'&&ch!='1') continue;
		c[cnt++] = !(ch-'0');
	}
	
	//show();
	Gauss(0);
	cnt = 0;
	for (i=size-1; i>=0; --i) {
		x[i] = c[i];
		for (j=size-1; j>i; --j)
			x[i] ^= x[j]*a[i][j];
		if (x[i]) cnt++;
	}
	
	printf("%d\n",cnt);
	for (pos=0; pos<size; ++pos)
		if (x[pos])
			printf("%d %d\n",pos/col+1,pos%col+1);
}
