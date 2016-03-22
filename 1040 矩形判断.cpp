#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

struct vec {
	int x,y;
	vec() {x=y=0;}
	vec(int xx,int yy) {x=xx; y=yy;}
	bool iszero() {return (x==0 && y==0);}
	inline operator *(vec p) {return x*p.x+y*p.y;}
};
int x1[4],y1[4],x2[4],y2[4];

bool plumb() {
	vec e[4];
	for (int i=0; i<4; ++i)
		e[i] = vec(x2[i]-x1[i],y2[i]-y1[i]);
	if (e[0].iszero()||e[1].iszero()||e[2].iszero()||e[3].iszero())
		return false;
	int cnt = 0;
	if (e[0]*e[1]==0) cnt++;
	if (e[0]*e[2]==0) cnt++;
	if (e[0]*e[3]==0) cnt++;
	if (cnt!=2) return false;
	cnt = 0;
	if (e[1]*e[0]==0) cnt++;
	if (e[1]*e[2]==0) cnt++;
	if (e[1]*e[3]==0) cnt++;
	if (cnt!=2) return false;
	return true;
}

int main() {
	int i,t;
	set<pii> vertex,midpoint;
	scanf("%d",&t);
	while (t--) {
		vertex.clear(); midpoint.clear();
		for (i=0; i<4; ++i) {
			scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
			vertex.insert(pii(x1[i],y1[i]));
			vertex.insert(pii(x2[i],y2[i]));
			midpoint.insert(pii((x1[i]+x2[i]),(y1[i]+y2[i])));
		}
		if (vertex.size()==4 && midpoint.size()==4 && plumb())
			puts("YES");
		else 
			puts("NO");
	}
}
