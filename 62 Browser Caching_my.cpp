#include <iostream>
using namespace std;

struct node {
	string web;
	node *next;
};
node *p;

void initLoop(int m) {
	p = new node();
	node *cur=p, *nxt;
	while (--m) {
		nxt = new node();
		cur->next = nxt;
		cur = nxt;
	}
	cur->next = p;
}

int main() {
	int n,m,i;
	node *cur,*nxt;
	string web;
	cin>>n>>m;
	initLoop(m);
	for (i=0; i<n; ++i){
		cin>>web;
		cur=p; nxt=cur->next;
		while (nxt!=p && nxt->web!=web) {
			cur=nxt; nxt=cur->next;
		}
		
		if (nxt==p) {
			if (p->web==web)
				puts("Cache");
			else {
				puts("Internet");
				p = p->next;
				p->web = web;
			}
		} 
		else {
			puts("Cache");
			cur->next = nxt->next;
			nxt->next = p->next;
			p->next = nxt;
			p = p->next;
		}
	}
}
