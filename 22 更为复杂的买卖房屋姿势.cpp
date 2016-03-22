#include <iostream>
#include <cstdio>
#include <cmath>
#define N 100010
using namespace std;

int w[N];

typedef struct node {
	int lb,rb;		//l/r border
	node *ln,*rn;	//l/r node
	int v;
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

void update(node* root,int l,int r,int newp,int op) {
	if ((root->lb==l)&&(root->rb==r)&&(op==1)) {
		root->v = newp*(r-l+1);
		root->lazy = true;
		return;
	}
	if ((r==l)&&(op==0)) {
		root->v += newp;
		root->lazy = true;
		return;
	}
	{
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
			update(root->ln,l,r,newp,op);
		else if(l>m)
			update(root->rn,l,r,newp,op);
		else {
			update(root->ln,l,m,newp,op);
			update(root->rn,m+1,r,newp,op);
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
	int n,m,op,l,r,i,newp;
	scanf("%d%d",&n,&m);
	node* root = new node(0,n);
	for (i=0; i<=n; ++i)
		scanf("%d",&w[i]);
	construct(root);
	
	while (m--) {
		scanf("%d%d%d%d",&op,&l,&r,&newp);
		if (op==2) show(root);
		else update(root,l,r,newp,op);
		printf("%d\n",root->v);
	}
	return 0;
}

