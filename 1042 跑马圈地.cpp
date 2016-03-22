#include <iostream>
#include <cstdio>
using namespace std;

int n,m,L;
int l,r,t,b;
int length[4],width[4];

void selectEdge(int *k1, int *k2) {
	int maxw=0,width[4],k,maxk;
	width[0]=l; width[1]=t; width[2]=m-r; width[3]=n-b;
	for (k=0; k<4; ++i)
		if (width[k]>maxw) {
			maxw = width[k];
			maxk = k;
		}
	*k1 = maxk;
	int kp=(k+1)%4, km=(k+3)%4;
	if (width[kp]>width[km]) *k2=kp;
	else *k2=km;
}

int main() {
	scanf("%d%d%d",&n,&m,&L);
	scanf("%d%d%d%d",&l,&r,&t,&b);
	width[0]=l; width[1]=t; width[2]=m-r; width[3]=n-b;
	length[0]=n; length[1]=m; length[2]=n; length[3]=m;
	int k1,k2,w=1;
	selectEdge(&k1,&k2);
	int i,l1,l2;
	l1 = (width[k1] + length[k1]) * 2;
	if (l1>=L) {
		i = min(length[k1], (int)sqrt(L/2));
		j = min(width[k1], L/2-i);
		printf("%d\n",i*j);
		return 0;
	} else {
		l2 = (L - l1) / 2;
		threshold = length[k2]
		if (l2)
	}

	printf("%d\n",ans);
}
