#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;
const int SIZE = 1e5+100;

struct Element {
	LL x;
	int y;
	Element() {x=0; y=0;}
};
Element a[SIZE],b[SIZE];

int cmp(Element a,Element b) {
	return (a.x<b.x);
}

int findIndex(int l,int r,LL x) {
	if (l==r) return l;
	int m = (l+r)/2;
	if (a[m].x>=x) return findIndex(l,m,x);
	else return findIndex(m+1,r,x);
}

map<LL,int> getSeq(int n) {
	map<LL,int> a;
	LL x; int y;
	for (int i=0; i<n; ++i) {
		scanf("%ld%d",&x,&y);
		if (a.find(x)==a.end()) a[x]=0;
		a[x] += y;
	}
	return a;
}

int SeqToArray(map<LL,int> e, Element *a) {
	map<LL,int>::iterator it;
	int i=0;
	for (it=e.begin(); it!=e.end(); ++it,++i) {
		
		a[i].x = it->first;
		a[i].y = it->second;
	}
	return e.size();
}

int main() {
	int n,m,t,x,y,i,j;
	map<LL,int> aa,bb;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&m);
		aa = getSeq(n);
		bb = getSeq(m);
		n = SeqToArray(aa,a);
		m = SeqToArray(bb,b);
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		//for (i=n-2; i>=0; i--)
			//a[i].y += a[i+1].y;
		
		/*for (i=n-1; i>=0; --i)
			printf("a[%d].x=%ld\ta[%d].y=%d\n",i,a[i].x,i,a[i].y);
		for (i=m-1; i>=0; --i)
			printf("b[%d].x=%ld\tb[%d].y=%d\n",i,b[i].x,i,b[i].y);*/
		int r=0;
		LL cnt=0, ans=0;
		for (i=0; i<n; i++) {
			while (r<m && a[i].x>b[r].x) cnt+=b[r].y,r++;
			ans += a[i].y * cnt;
		}

		/*LL ans = 0;
		for (j=0; j<m; j++) {
			if (b[j].x>=a[n-1].x) break;
			if (b[j].x<a[0].x)
				ans += b[j].y * a[0].y;
			else {
				i = findIndex(0,n-1,b[j].x);
				if (a[i].x==b[j].x) i++;
				ans += b[j].y * a[i].y;
				//printf("j=%d i=%d ans=%ld\n",j,i,ans);
			}
		} */
		printf("%lld\n",ans);
	}
}
