#include <iostream>
#include <vector>
#define N 100000
using namespace std;

int max(int a, int b) {
	return a>b? a:b;
}

int dfs(int root, int pre, vector<vector<int> >& edge, int& ans) {
	int l1=0, l2=0, i;
	if ((edge[root].size()==1)&&(edge[root][0]==pre))
		return 1;
	for (i=0; i<edge[root].size(); ++i) {
		if (edge[root][i]==pre) continue;
		int l = dfs(edge[root][i], root, edge, ans);
		if (l>l1) {l2=l1; l1=l;}
		else l2 = max(l2, l);
	}
	ans = max(l1+l2, ans);
	return l1+1;
}

int main() {
	int i,n,a,b;
	cin>>n;
	vector<vector<int> > edge(n);
	for (i=0; i<n-1; i++) {
		cin>>a>>b;
		--a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	int ans=0;
	dfs(0, -1, edge, ans);
	cout<<ans<<endl;
	return 0;
}
