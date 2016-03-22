#include <cstdio>
typedef unsigned long long ull;

const int N = 1e5+10;
int a[N], n, buffer[N];

void init(int size) {
	int i,pos,p;
	for (i=0; i<=size; ++i)
		buffer[i] = 0;
	for (i=0; i<size; i++) {
		pos = i+1;
		p = a[i];
		while (p>buffer[pos>>1] && pos>1) {
			buffer[pos] = buffer[pos>>1];
			pos = pos>>1;
		}
		buffer[pos] = p;
	}
}

int insert(int size, int p) {
	buffer[0] = buffer[1];
	buffer[1] = p;
	int len = size+1;
	int i=1, l=i<<1, r=(i<<1)+1;
	while ((l<len && p<buffer[l]) || (r<len && p<buffer[r])) {
		if (r<len && buffer[l]<buffer[r]) {
			buffer[i] = buffer[r];
			i = r;
		} else {
			buffer[i] = buffer[l];
			i = l;
		}
		l = i<<1;
		r = (i<<1)+1;
	}
	buffer[i] = p;
	/*printf("insert %d, buffer=",p);
	for (i=0; i<len; ++i)
		printf(" %d",buffer[i]);
	printf("\n");*/
	return buffer[0];
}

ull sp(int size) {
	int i;
	ull v=0;
	init(size);
	/*printf("size=%d, buffer= ",size);
	for (i=0; i<=size; ++i)
		printf("%d ",buffer[i]);
	printf("\n");*/
	for (i=0; i<n-size; ++i) {
		int m = insert(size, a[i+size]);
		v += (i+1)*m;
		//printf("sp=%d, %d * %d\n",size,i+1,m);
	}
	for (i=n-size; i<n; ++i) {
		int m = insert(size, 0);
		v += (i+1)*m;
		//printf("sp=%d, %d * %d\n",size,i+1,m);
	}
	return v;
}
int main() {
	int i,l,r,m;
	ull q,vl,vr,vm;
	scanf("%d %lld", &n, &q);
	for (i=0; i<n; ++i)
		scanf("%d", &a[i]);
	
	l=1; r=n;
	vl = sp(r);
	/*for (i=1; i<=n; ++i)
		printf("sp=%d\n",sp(i));*/
	if (vl>q) printf("-1\n");
	else {
		while (l<r) {
			m = (l+r)>>1;
			vm = sp(m);
			if (vm>q) l=m+1;
			else r=m;
			//printf("l=%d, m=%d, r=%d\n",l,m,r);
		}
		printf("%d\n",l);
	}
	return 0;
}
