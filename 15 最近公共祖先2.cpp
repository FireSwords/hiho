#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

typedef struct person {
	string name;
	int level;
	person* father;
	set<person*> sons;
	person() {level=-1; father=NULL;}
	person(string m_name) {name=m_name; person();}
};

map<string,person*> ref;

person* getPerson(string name) {
	person* a;
	map<string,person*>::iterator it = ref.find(name);
	if (it==ref.end()) {
		a = new person(name);
		ref[name] = a;
	} else {
		a = it->second;
	}
	return a;
}

void setLevel(person* cur, int level) {
	cur->level = level;
	set<person*>::iterator it;
	for (it=cur->sons.begin(); it!=cur->sons.end(); ++it)
		setLevel(*it, level+1);
}

int main() {
	int i,n,m;
	string fn,sn;
	person *fa,*so,*root;
	cin>>n;
	for (i=0; i<n; ++i) {
		cin>>fn>>sn;
		fa = getPerson(fn);
		so = getPerson(sn);
		if (i==0) root = fa;
		(fa->sons).insert(so);
		so->father = fa;
	}
	setLevel(root,0);
	
	cin>>m;
	string q1,q2;
	person *p1,*p2;
	for (i=0; i<m; ++i) {
		cin>>q1>>q2;
		p1 = ref.find(q1)->second;
		p2 = ref.find(q2)->second;
		while(p1->level<p2->level)
			p2 = p2->father;
		while(p1->level>p2->level)
			p1 = p1->father;
		while(p1->name!=p2->name)
			p1 = p1->father, p2 = p2->father;
		printf("%s\n", (p1->name).c_str());
	}
}
