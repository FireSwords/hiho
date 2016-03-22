#include <iostream> 
using namespace std;

const int N = 100000;
const int INF = 0x3fffffff;

int h[N],size=0;

void in() {
	int val;
	cin>>val;
	int p = ++size;
	while (val>h[p>>1]) {
		h[p] = h[p>>1];
		p = p>>1;
	}
	h[p] = val;	
}

void out() {
	cout<<h[1];
	int tmp = h[size];
	size--;
	
	int l,r,p=1;
	bool flag=true;
	while (flag&&((p<<1)<size)) {
		l=p<<1; r=l+1;
		if (tmp<h[r] && h[l]<h[r]) {
			h[p] = h[r];
			p = r;
		}
		else if (tmp<h[l] && h[r]<h[l]) {
			h[p] = h[l];
			p = l;
		}
		else flag=false;
	}
	h[p] = tmp;
}

int main() {
	int n;
	char op;
	cin>>n;
	h[0] = INF;
	while(n--) {
		cin>>op;
		if (op=='A') in();
		else out();
	}
}
