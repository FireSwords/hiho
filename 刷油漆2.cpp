#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

#define N 100

int v[N][N]={0};
set<int> edge[N];

int maxValue(int root, int pre, int m) { //sn-selectedNode, nb-neighbor
	set<int>::iterator it;

	nb1.erase(nb1.begin());
	v1 = maxValue(sn, nb1, m);
	int fn = *nb.begin();
	sn.insert(fn);
	for (it=edge[fn].begin(); it!=edge[fn].end(); ++it)
		if (sn.find(*it)==sn.end()) 
			nb1.insert(*it);
	v2 = maxValue(sn, nb1, m-1) + v[fn];
	maxv = max(max(v1, v2), maxv);
	
	return maxv;
}

int main() {
	int i,n,m,a,b;
	cin>>n>>m;
	for (i=0; i<n; ++i)
		cin>>v[i];
	for (i=0; i<n-1; i++) {
		cin>>a>>b;
		--a; --b;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	f(0);
	return 0;
}
