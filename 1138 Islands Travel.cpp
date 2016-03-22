#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1e5+10;
int p[N][2];
bool vis[N];
int n;

int calcDist(int i,int j) {
	int dx,dy;
	dx = p[i][0]-p[j][0];
	if (dx<0) dx=-dx;
	dy = p[i][1]-p[j][1];
	if (dy<0) dy=-dy;
	return (dx<=dy ? dx:dy);
}

int findPath(int u, int v) {
	int duv = calcDist(u, v);
	int dmin = duv;
	int k, kmin=0;
	for (k=2; k<n; ++k) {
		if (vis[k]) continue;
		int dukv = calcDist(u,k) + calcDist(k,v);
		if (dukv < dmin) {
			dmin=dukv; kmin=k;
		}
	}
	if (kmin) {
		vis[kmin] = true;
		return findPath(u,kmin)+findPath(kmin,v);
	}
	else return duv;
}

int main() {
	int i,k;
	scanf("%d",&n);
	for (i=1; i<=n; ++i)
		scanf("%d%d",&p[i][0],&p[i][1]);
	vis[1] = vis[n] = true;
	printf("%d\n",findPath(1,n));
}
