#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e4+5;
char str[N],cnt[N];
int n;

int show() {
	printf("%s\n",str+1);
	for (int i=1; i<=n; ++i)
		printf("%d ",cnt[i]);
	putchar('\n');
}

void rotate() {
	int p;
	for (p=1; p<=n; ++p) {
		char ch = str[p] + cnt[p];
		if (ch>'Z') ch=ch-'Z'+'A'-1;
		str[p] = ch;
	}
	memset(cnt+1,0,n);
}

int main() {
	int m,i,j,k,p,op;
	char x;
	string cmd;
	scanf("%d%d",&n,&m);
	scanf("%s", str+1);	
	while (m--) {
		cin>>cmd>>op;
		switch (op) {
			case 1: {
				cin>>i>>j>>x;
				memset(str+i,x,j-i+1);
				memset(cnt+i,0,j-i+1);
				//show();
				break;
			}
			case 2: {
				cin>>i>>j>>k;
				k = k % 26;
				for (p=i; p<=j; ++p)
					cnt[p] = (cnt[p]+k) % 26;
				//show();				
				break;
			}
			case 3: {
				cin>>k;
				char tmp[N];
				rotate();
				strncpy(tmp+1,str+1,n+1);
				strncpy(str+1,tmp+k+1,n-k);
				strncpy(str+n-k+1,tmp+1,k);
				memset(cnt+1,0,n);
				//show();
				break;
			}
			case 4:{
				cin>>i>>j;
				for (p=i; p<=j; ++p)
					cnt[p] = (cnt[p]+p-i+1) % 26;
				//show();
				break;
			}
		}
	}
	
	rotate();
	printf("%s",str+1);
}
