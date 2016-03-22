#include <iostream>
#include <cstdio>
#include <cmath>
#define N 1000010
using namespace std;

int w[N];

typedef struct node {
	int lb,rb;		//l/r border
	node *ln,*rn;	//l/r node
	int v;
	node(int l, int r) {lb=l;rb=r;ln=NULL;rn=NULL;}
};

void construct(node* root) {
	if (root->lb==root->rb)
		root->v = w[root->lb];
	else {
		int m = (root->lb+root->rb)/2;
		node* left = new node(root->lb,m);
		node* right = new node(m+1, root->rb);
		root->ln = left;
		root->rn = right;
		construct(root->ln);
		construct(root->rn);
		root->v = min(root->ln->v, root->rn->v);
	}
}

int quiry(node* root, int l, int r) {
	if ((l==root->lb)&&(r==root->rb))
		return root->v;
	int m = (root->lb+root->rb)/2;
	if (r<=m)
		return quiry(root->ln,l,r);
	else if (l>m)
		return quiry(root->rn,l,r);
	else
		return min(quiry(root->ln,l,m),quiry(root->rn,m+1,r));
}

void update(node* root, int pos) {
	if ((root->lb==pos)&&(root->rb==pos))
		root->v = w[pos];
	else {
		int m = (root->lb+root->rb)/2;
		if (pos<=m) 
			update(root->ln, pos);
		else 
			update(root->rn, pos);
		root->v = min(root->ln->v, root->rn->v);
	}
}

int main() {
	int n,q,op,l,r,i;
	scanf("%d",&n);
	node* root = new node(1,n);
	//w = (int*)malloc(sizeof(int)*(n+1));
	for (i=1; i<=n; ++i)
		scanf("%d",&w[i]);
	construct(root);
	
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&op);
		if (op) {
			scanf("%d", &l);
			scanf("%d", &w[l]);
			update(root, l);	
		} else {
			scanf("%d%d",&l,&r);
			printf("%d\n", quiry(root,l,r));
		}
	}
	return 0;
}

