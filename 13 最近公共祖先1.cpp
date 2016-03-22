#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int i,n,m;
	string f,s;
	map<string,string> s_f;
	set<string> fpath;

	cin>>n;
	for (i=0; i<n; ++i) {
		cin>>f>>s;
		s_f[s] = f;
	}
	
	string q1,q2;
	map<string,string>::iterator it;
	cin>>m;
	for (i=0; i<m; ++i) {
		fpath.clear();
		cin>>q1>>q2;
		fpath.insert(q1);
		it = s_f.find(q1);
		while (it!=s_f.end()) {
			f = it->second;
			fpath.insert(f);
			it = s_f.find(f);
		}
		
		bool flag = false;
		if (fpath.find(q2)!=fpath.end()) {
			cout<<q2<<endl;
			flag = true;
		}
		it = s_f.find(q2);
		while ((!flag)&&(it!=s_f.end())) {
			f = it->second;
			if (fpath.find(f)!=fpath.end()) {
				cout<<f<<endl;
				flag = true;
			}
			it = s_f.find(f);
		}
		if (!flag) cout<<-1<<endl;
	}
	
	return 0;
}
