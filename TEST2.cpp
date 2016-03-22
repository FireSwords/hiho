#include <cstdio>
#include <cstring>

const int L = 105;
char str[L];
int len;

int preprocess() {
	int lastlen=0,cnt=0;
	while (lastlen!=len) {
		lastlen = len;
		int p1=1, p2=2;
		while (p2<len) {
			while(p2<len && str[p1]==str[p2]) p2++;
			if (p2-p1==2) {
				memset(str+p1,'#',2);
				cnt += 2;				
			}
			if (p2-p1>2) {
				memset(str+p1+1,'#',p2-p1-1);
				cnt += p2-p1-1;
			}
			p1=p2; p2=p1+1;
		}
		
		p1=0; p2=0;
		char tmp[L];
		memcpy(tmp,str,L);
		memset(str,0,L);
		while (tmp[p1]) {
			if (tmp[p1]!='#') {
				str[p2] = tmp[p1];
				p2++;
			}
			p1++;
		}
		len = strlen(str);
	}
	return cnt;
}

int process() {
	int cnt=0,c,i,l,r;
	for (i=1; i<len; ++i) {
		l=i-1; r=i+1;
		while(str[l]==str[r])
			l--, r++;
		c = r-l-1;
		if (c>cnt) cnt=c;
	}
	return cnt;
}

int main() {
	int t,cnt;
	scanf("%d",&t);
	while (t--) {
		memset(str,0,L);
		scanf("\n%s",str+1);
		str[0] = '$';
		len = strlen(str);
		cnt = preprocess();
		printf("%s\t%d\t%d\n",str,cnt,len);
		cnt += process();
		printf("%d\n",cnt+1);
	}
}
