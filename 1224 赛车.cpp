#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5+5;
const int root = 1;
struct Edge {
	int to;
	Edge *next;
};
Edge *p[N];

void addEdge(int a, int b) {
	Edge *e = new Edge();
	e->to = b;
	e->next = p[a];
	p[a] = e;
}

int getLength(int r, int* first, int *second) {
	int l1,l2,l;
	l = l1 = l2 = 0;
	for (Edge *e=p[r]; e; e=e->next) {
		l = getLength(e->to,first,second) + 1;
		if (l>l1) {l2=l1; l1=l;}
		else if (l>l2) l2=l;
	}
	*first = max(*first, l1);
	*second = max(*second, l2);
	//printf("%d l1=%d l2=%d\n",r,*first,*second);
	return l1;
}

int main() {
	int n,a,b,i;
	scanf("%d",&n);
	for (i=1; i<=n-1; ++i) {
		scanf("%d%d",&a,&b);
		addEdge(a,b);
	}
	
	int l1=0,l2=0;
	getLength(root,&l1,&l2);
	printf("%d\n",l1+l2);
}
