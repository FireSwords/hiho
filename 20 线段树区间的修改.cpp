#include <iostream>
#include <cstdio>
#include <cmath>
#define N 100010
using namespace std;

int w[N];

typedef struct node {
	int lb,rb;		//l/r border
	node *ln,*rn;	//l/r node
	long v;
	bool lazy;
	node(int l, int r) {lb=l;rb=r;ln=NULL;rn=NULL;lazy=false;}
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
		root->v = root->ln->v + root->rn->v;
	}
}

long quiry(node* root, int l, int r) {
	if ((l==root->lb)&&(r==root->rb))
		return root->v;
	int m = (root->lb+root->rb)/2;
	if (root->lazy) {
		int n = root->rb - root->lb + 1;
		int nl = m - root->lb +1;
		int nr = n - nl;
		root->ln->v = root->v * nl / n;
		root->ln->lazy = true;
		root->rn->v = root->v * nr / n;
		root->rn->lazy = true;
		root->lazy = false;
	}
	if (r<=m)
		return quiry(root->ln,l,r);
	else if (l>m)
		return quiry(root->rn,l,r);
	else
		return quiry(root->ln,l,m)+quiry(root->rn,m+1,r);
}

void update(node* root,int l,int r,int newp) {
	if ((root->lb==l)&&(root->rb==r)) {
		root->v = newp*(r-l+1);
		root->lazy = true;
	}
	else {
		int m = (root->lb+root->rb)/2;
		if (root->lazy) {
			int n = root->rb - root->lb + 1;
			int nl = m - root->lb +1;
			int nr = n - nl;
			root->ln->v = root->v * nl / n;
			root->ln->lazy = true;
			root->rn->v = root->v * nr / n;
			root->rn->lazy = true;
			root->lazy = false;
		}
		if (r<=m) 
			update(root->ln,l,r,newp);
		else if(l>m)
			update(root->rn,l,r,newp);
		else {
			update(root->ln,l,m,newp);
			update(root->rn,m+1,r,newp);
		}
		root->v = root->ln->v + root->rn->v;
	}
}

void show(node* root) {
	printf("l=%d\tr=%d\tlazy=%d\tv=%d\n",root->lb,root->rb,root->lazy,root->v);
	if (root->ln) {
		show(root->ln);
		show(root->rn);
	}
}

int main() {
	int n,q,op,l,r,i,newp;
	scanf("%d",&n);
	node* root = new node(1,n);
	//w = (int*)malloc(sizeof(int)*(n+1));
	for (i=1; i<=n; ++i)
		scanf("%d",&w[i]);
	construct(root);
	
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&op);
		if (op==1) {
			scanf("%d%d%d",&l,&r,&newp);
			update(root,l,r,newp);	
		} else if(op==0){
			scanf("%d%d",&l,&r);
			printf("%ld\n", quiry(root,l,r));
		} //else show(root);
	}
	return 0;
}

