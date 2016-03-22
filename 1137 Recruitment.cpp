#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 110;
int n,x,y,b;
int v[N], s[N], g[N], ans[N];
struct Select {
	vector<int> p;
	int v,s;
	bool flag;
	Select() {v=s=0; flag=false;}
	Select(bool f) {v=s=0; flag=f;}
};

void show(int i,Select v1,Select v2) {
	printf("i = %d:\n",i);
	printf("v1: v=%d s=%d flag=%d\n\t",v1.v,v1.s,v1.flag);
	for (int k=0; k<v1.p.size(); ++k)
		printf("%d ",v1.p[k]);
	putchar('\n');
	printf("v2: v=%d s=%d flag=%d\n\t",v2.v,v2.s,v2.flag);
	for (int k=0; k<v2.p.size(); ++k)
		printf("%d ",v2.p[k]);
	putchar('\n');
}

Select func(int i,int m,int f,int b) {
	if (i==0) {
		if (m==0 && f==0) return *new Select(true);
		else return *new Select(false);
	}
	 
	Select v1,v2;
	v1 = func(i-1,m,f,b);
	if (b>s[i]) {
		if (g[i] && m>0)
			v2 = func(i-1,m-1,f,b-s[i]);
		else if (!g[i] && f>0)
			v2 = func(i-1,m,f-1,b-s[i]);
		if (v2.flag) {
			v2.p.push_back(i);
			v2.v = v2.v + v[i];
			v2.s = v2.s + s[i];
		}
	}
	//show(i,v1,v2);
	
	if (v1.flag&&v2.flag) {
		if (v1.v>v2.v) return v1;
		if (v2.v>v1.v) return v2;
		vector<int> p1(v1.p),p2(v2.p);
		if (p2.empty()) return v1;
		if (p1.empty()) return v2;
		int k = 0;
		while (p1[k]==p2[k]) k++;
		if (p1[k]<p2[k]) return v1;
		else return v2;
	} else {
		if (v1.flag) return v1;
		if (v2.flag) return v2;
		return *new Select(false);
	}
}

int main() {
	char ch;
	scanf("%d%d%d%d",&n,&x,&y,&b);
	for (int i=1; i<=n; ++i) {
		cin>>ch>>v[i]>>s[i];
		if (ch=='M') g[i]=1;
		else g[i]=0;
	}
		
	Select ans = func(n,x,y,b);
	printf("%d %d\n",ans.v,ans.s);
	for (int i=0; i<ans.p.size(); ++i)
		printf("%d ",ans.p[i]);
	putchar('\n');
}
