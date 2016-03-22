#include <cstdio>
#include <cstring>

const int N = 2e4;
int sg[N+1];

void mex() {
	int i,k;
	int mark[2*N+1],temp_mark[2*N+1];
	sg[0] = 0;
	mark[0] = 1;
	for (k=1; k<=N; ++k) {
		memcpy(temp_mark,mark,sizeof(mark));
		for (i=1; i<=k/2; ++i) {
			temp_mark[sg[i]^sg[k-i]] = 1;
		}
		i = 1;
		while(temp_mark[i]) ++i;
		sg[k] = i;
		mark[i] = 1;
	}
	/*for (i=0; i<=12; ++i)
		printf("%d ",sg[i]);
	printf("\n");*/
}

int main() {
	mex();
	int n,a,ans=0;
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&a);
		ans = ans ^ sg[a];
	}
	
	if (ans) printf("Alice\n");
	else printf("Bob\n");
}
