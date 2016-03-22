#include <cstdio>
#include <cstring>
#include <string.h>

#define L 1500000

char str[L];

int calc(char* str)
{
	int i=1, e, s, ans=1;
	while (str[i])
	{
		s=i; e=i;
		while(str[s]==str[e+1]) ++e;
		i=e;
		while(str[s-1]==str[e+1]) ++e, --s;
		if(e-s+1>ans) ans=e-s+1;
		++i;
	}
	return ans;
}

int main()
{
	int n,N;
	scanf("%d", &N);
	str[0] = '#';
	for (n=0; n<N; ++n)
	{
		scanf("%s", str+1);
		printf("%d\n", calc(str));
	}
	return 0;
}
