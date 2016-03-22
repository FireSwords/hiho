#include <iostream>
#include <vector>
using namespace std;
#define N 100

vector<char> edge[N];
int v[N], f[N][N]={0};
int n,m;

void post(char pre, char root) {
	vector<char>::iterator it;
	for (it=edge[root].begin(); it!=edge[root].end(); ++it) {
		if (*it==pre) continue;
		post(root, *it);
	}
	
	f[root][0] = 0;
	f[root][1] = v[root];
	char child, m_root, m_child;
	for (it=edge[root].begin(); it!=edge[root].end(); ++it) {
		child = *it;
		for (m_root=m; m_root>1; --m_root)
			for (m_child=1; m_child<m_root; ++m_child)
				f[root][m_root] = max(f[root][m_root], f[root][m_root-m_child] + f[child][m_child]);
	}
}

int main() {
	cin>>n>>m;
	int i,a,b;
	for (i=0; i<n; ++i)
		cin>>v[i];
	for (i=0; i<n-1; ++i) {
		cin>>a>>b;
		--a; --b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	post(-1, 0);
	cout<<f[0][m]<<endl;
	return 0;
}
