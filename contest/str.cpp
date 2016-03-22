#include <cstdio>
#include <cstring>

char s[100000];

void output(char* head,char *tail,int n1,int n2) {
	int i,j;
	if (n2==0) {
		for (i=0; i<n1; ++i)
			putchar(head[i]);
		putchar('\n');
		return;
	}
	for (i=0; i<n2; ++i) {
		//printf("%c", p[i]);
		char *nhead = new char[n1+1];
		char *ntail = new char[n2-1];
		strncpy(nhead, head, n1);
		nhead[n1] = tail[i];
		strncpy(ntail, tail, i);
		strncpy(ntail+i, tail+i+1, n2-i-1);
		/*for (j=0; j<i; ++j)
			ntail[j] = tail[j];
		for (j=i+1; j<n2; ++j)
			ntail[j-1] = tail[j];*/
		output(nhead,ntail,n1+1,n2-1);
	}
} 

int main() {
	scanf("%s",s);
	int n = strlen(s);
	char *h =NULL;
	output(h,s,0,n);
	return 0;
}
