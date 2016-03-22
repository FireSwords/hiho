#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string.h>
#define N 100001
using namespace std;

struct edge {
	int u,v,len;
};
edge* e;
int rep[N];
FILE* fp = NULL;

int inputEdges(int m) {
	typedef pair<int,int> pii;
	int i,v1,v2,len;
	map<pii,int> edgemap;
	for (i=0; i<m; ++i) {
		//fscanf(fp,"%d%d%d",&v1,&v2,&len);
		//printf("%d %d %d\n",v1,v2,len);
		scanf("%d%d%d",&v1,&v2,&len);
		if (v1>v2) swap(v1,v2);
		map<pii,int>::iterator it = edgemap.find(pii(v1,v2));
		if (it==edgemap.end())
			edgemap[pii(v1,v2)]=len;
		else if (len<it->second)
			it->second = len;
	}
	
	e = (edge*)malloc(sizeof(edge)*edgemap.size());
	map<pii,int>::iterator it;
	i=0;
	for (it=edgemap.begin(); it!=edgemap.end(); ++it,++i) {
		pii p = it->first;
		e[i].len = it->second;
		e[i].u = p.first;
		e[i].v = p.second;
	}
	return edgemap.size();
}

bool cmp(edge a, edge b) {
	return a.len<b.len;
}

int findrep(int x) {
	if (rep[x]==x)
		return x;
	else {
		rep[x] = findrep(rep[x]);
		return rep[x];
	}
}

void show(edge* e, int m) {
	printf("=====================\n");
	for (int i=0; i<m; ++i)
		printf("%d %d %d\n",e[i].u,e[i].v,e[i].len);
	printf("=====================\n");
}

int main() {
	int i,n,m;
	//fp = fopen("a.txt","r");
	//fscanf(fp,"%d%d",&n,&m);
	//printf("%d %d\n",n,m);
	scanf("%d%d",&n,&m);
	//m = inputEdges(m);
	//fclose(fp);
	int v1,v2,len;
	e = (edge*)malloc(sizeof(edge)*m);
	for (i=0; i<m; ++i) {
		scanf("%d%d%d",&v1,&v2,&len);
		e[i].u=v1; e[i].v=v2;
		e[i].len=len;
	}
	for (i=1; i<=n; ++i)
		rep[i] = i;
	sort(e,e+m,cmp);
	//show(e,m);
	
	int count=0,ans=0;
	for (i=0; count<n-1; ++i) {
		if (findrep(e[i].u)!=findrep(e[i].v)) {
			rep[findrep(e[i].u)] = findrep(e[i].v);
			ans += e[i].len;
			++count;
			//rep[findrep(e[i].u)] = findrep(e[i].v);
		}
	}
	printf("%d\n",ans);
}
