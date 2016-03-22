#include <iostream>
#include <cstdio>
#include <map>
#define N 100000*2
using namespace std;

map<string,int> ref;
int rep[N]={-1}, id=0;

void newperson(string name) {
	if (ref.find(name)==ref.end()) {
		ref[name] = id;
		rep[id] = id;
		++id;
	}
}

int findrep(int x) {
	if (x==rep[x]) 
		return x;
	else {
		rep[x] = findrep(rep[x]);
		return rep[x];
	}
}

void quiry(string a, string b) {
	map<string,int>::iterator ita,itb;
	ita = ref.find(a);
	itb = ref.find(b);
	if ((ita!=ref.end())&&(itb!=ref.end())) {
		int ida = ita->second;
		int idb = itb->second;
		if (findrep(ida)==findrep(idb)) {
			cout<<"yes"<<endl;
			return;
		}
	}
	cout<<"no"<<endl;
	return;
}

void connect(string a, string b) {
	int ida,idb;
	ida = ref.find(a)->second;
	idb = ref.find(b)->second;
	rep[findrep(ida)] = findrep(idb);
}

int main() {
	int n,i,op;
	string a,b;
	cin>>n;
	for (i=0; i<n; ++i) {
		cin>>op>>a>>b;
		newperson(a);
		newperson(b);
		if (op) quiry(a,b);
		else connect(a,b);
	}
	return 0;
}
