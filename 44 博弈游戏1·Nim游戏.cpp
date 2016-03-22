#include <cstdio>

int main() {
	int n,i,a,ans=0;
	scanf("%d",&n);
	for (i=0; i<n; ++i) {
		scanf("%d",&a);
		ans = ans ^ a;
	}
	if (ans) printf("Alice\n");
	else printf("Bob\n");
}
