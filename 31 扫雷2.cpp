#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
// UN -- Unknown Neighbors
FILE* fp;

typedef pair<int,int> pii;
const int N = 200;
int map[N][N],ans[N][N],n,m; 
struct cnt{
	int y,n;
	cnt() {y=n=0;}
	inline bool operator!= (cnt a) {return (a.n!=n||a.y!=y);}
};

void initMap() {
	int i,j; 
	fscanf(fp,"%d%d",&n,&m);
	//printf("%d %d\n",n,m);
	//scanf("%d%d",&n,&m);
	for (i=0; i<n; ++i) {
		for (j=0; j<m; ++j) {
			fscanf(fp,"%d",&map[i][j]);
			//printf(" %2d",map[i][j]);
			//scanf("%d",&map[i][j]);
			ans[i][j] = -1;
		}
		//putchar('\n');
	}
}

//设置邻居为a值 
void setUN(set<pii> n,int a) {
	set<pii>::iterator it;
	int i,j;
	for (it=n.begin(); it!=n.end(); ++it) {
		i = (*it).first;
		j = (*it).second;
		ans[i][j] = a;
	}
}

//得到为探明邻居的set 
set<pii> getUN(int x,int y) {
	set<pii> nb;
	int i,j,cnt=0;
	for (i=x-1; i<=x+1; ++i)
		for (j=y-1; j<=y+1; ++j) {
			if (i<0||i>=n||j<0||j>=m) continue;
			if (map[i][j]==-1) 
				nb.insert(pii(i,j));
		}
	return nb;
}

//判断是否子集 
bool isSub(set<pii> n1, set<pii> n2) {
	set<pii> *a,*b;
	if (n1.size()>n2.size()) {a=&n1; b=&n2;}
	else {a=&n2; b=&n1;}
	set<pii>::iterator ia,ib;
	for (ib=b->begin(); ib!=b->end(); ++ib){
		ia = a->find(*ib);
		if (ia==a->end())
			return false;
	}
	return true;
}

//得到非公共部分 
set<pii> unCommSet(set<pii> n1, set<pii> n2) {
	set<pii> *a,*b;
	set<pii> c;
	c.clear();
	if (n1.size()==n2.size()) return c;
	if (n1.size()>n2.size()) {a=&n1; b=&n2;}
	else {a=&n2; b=&n1;}
	set<pii>::iterator ia,ib;
	for (ia=a->begin(); ia!=a->end(); ++ia){
		ib = b->find(*ia);
		if (ib==b->end())
			c.insert(*ia);
	}
	return c;
}

void process() {
	int i,j,nn1,nn2;
	set<pii> n1,n2;
	for (i=0; i<n; ++i) 
		for (j=0; j<m; ++j) {
			if (map[i][j]==-1) continue;
			ans[i][j] = 0;
			n1 = getUN(i,j);
			//tip1
			if (map[i][j]==0) {
				setUN(n1,0);
			}
			//tip2
			else if (map[i][j]==n1.size()) {
				setUN(n1,1);
			} else {
				//tip3
				int ii,jj;
				for (ii=i-1; ii<=i+1; ++ii)
					for (jj=j-1; jj<=j+1; ++jj) {
						if (ii<0||ii>=n||jj<0||jj>=m) continue;
						if (ii==i && jj==j) continue;
						if (map[ii][jj]==-1) continue;
						n2 = getUN(ii,jj);
						int s1 = n1.size() - n2.size();
						int s2 = map[i][j] - map[ii][jj];
						if ((s1==s2)&&(isSub(n1,n2)))
							setUN(unCommSet(n1,n2),1);
					}
			}
		}
}

cnt cntAns() {
	int i,j;
	cnt c;
	for (i=0; i<n; ++i)
		for (j=0; j<m; ++j)
			if (map[i][j]==-1)
				if (ans[i][j]==0) c.n++;
				else if (ans[i][j]==1) c.y++;
	return c;
}

void showAns() {
	printf("------------------------------------\n");
	int i,j;
	for (i=0; i<n; ++i) {
		for (j=0; j<m; ++j)
			printf(" %2d",ans[i][j]);
		putchar('\n');
	}
	printf("------------------------------------\n");
}

int main() {
	int i,j,task;
	int y,n,lasty,lastn;
	fp = fopen("a.txt","r");
	fscanf(fp,"%d",&task);
	//printf("%d\n",task);
	//scanf("%d",&task);
	while (task--) {
		initMap();
		process();
		cnt c = cntAns();
		showAns();
		printf("%d %d\n",c.y,c.n);
		//printf("===============================\n");
	}
	fclose(fp);
}
