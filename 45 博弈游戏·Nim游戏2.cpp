#include <cstdio>

int main() {
	char buf[10001];
	int n,i=0,ans=0;
	scanf("%d",&n);
	scanf("%s",buf);
	while(buf[i]) {
		if (buf[i]=='H')
			ans = ans ^ (i+1);
		i++;
	}
	if (ans) printf("Alice\n");
	else printf("Bob\n");
}
