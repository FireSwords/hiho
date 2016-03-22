#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <map> 
#define N 100010
using namespace std;

int zone[N][2];
int flag[N]={0};

typedef struct node {
	int lb,rb;		//l/r border
	node *ln,*rn;	//l/r node
	int v;
	bool lazy;
	node(int l, int r) {lb=l;rb=r;ln=NULL;rn=NULL;lazy=false;}
};

void convert(int n) {
	list<int> point;
	map<int,int> ref;
	int i;
	for (i=0; i<n; ++i) {
		point.push_back(zone[i][0]);
		point.push_back(zone[i][1]);
	}
	point.sort();
	list<int>::iterator it;
	for (it=point.begin(),i=0; it!=point.end(); ++it,++i)
		ref[*it] = i;
	for (i=0; i<n; ++i) {
		zone[i][0] = ref[zone[i][0]];
		zone[i][1] = ref[zone[i][1]];
	}
}

int search(node* root) {
	if (root->lazy)
		flag[root->v] = 1;
	else {
		search(root->ln);
		search(root->rn);
	}
}

void update(node* root,int l,int r,int poster) {
	if ((root->lb==l)&&(root->rb==r)) {
		root->v = poster;
		root->lazy = true;
	}
	else {
		int m = (root->lb+root->rb)/2;
		if (root->lazy) {
			if (root->ln==NULL) {
				node* left = new node(root->lb, m);
				node* right = new node(m, root->rb);
				root->ln = left;
				root->rn = right;
			}
			root->ln->v = root->v;
			root->ln->lazy = true;
			root->rn->v = root->v;
			root->rn->lazy = true;
			root->lazy = false;
		}
		if (r<=m) 
			update(root->ln,l,r,poster);
		else if(l>=m)
			update(root->rn,l,r,poster);
		else {
			update(root->ln,l,m,poster);
			update(root->rn,m,r,poster);
		}
		root->v = max(root->ln->v, root->rn->v);
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
	scanf("%d%d",&n,&l);
	for (i=0; i<n; ++i)
		scanf("%d%d",&zone[i][0],&zone[i][1]);
	convert(n);
		
	node* root = new node(0, 2*n-1);
	root->v = -1;
	root->lazy = true;
	
	for (i=0; i<n; ++i)
		update(root,zone[i][0],zone[i][1],i);	
	//show(root);
	
	search(root);
	int ans = 0;
	for (i=0; i<n; ++i)
		if (flag[i]) ans++;
	printf("%d\n",ans);
	return 0;
}

