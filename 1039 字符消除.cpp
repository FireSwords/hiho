#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int L = 110;
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

int ans1(char *ss) {
	memcpy(str,ss,L);
	int cnt = 0;
	len = strlen(str);
	cnt = preprocess();
	//printf("%s\t%d\t%d\n",str,cnt,len);
	cnt += process();
	return cnt+1;
}

int eliminate( char * s ) {
	int len = strlen( s ),score=0;
	if (len == 0) return 0;
	bool isEliminated[L];
	for (int i = 0; i < len; i++) isEliminated[i] = false;
	for (int i = 1; i < len - 1; i++) {
		if (s[i] == s[i - 1] || s[i] == s[i + 1]) isEliminated[i] = true;
	}
	if (s[0] == s[1]) isEliminated[0] = true;
	if (s[len - 1] == s[len - 2]) isEliminated[len - 1] = true;
	char newStr[L];
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (!isEliminated[i]) {
			newStr[j] = s[i];
			j++;
		}
		else score++;
	}
	newStr[j] = 0;
	strcpy( s, newStr );
	return score;
}

int ans2(char *s) {
	int len = strlen( s );
	int maxScore = 0;
	for (int i = 0; i <= len; i++) {
		for (char insert = 'A'; insert <= 'C'; insert++) {
			char newStr[L];
			strcpy( newStr, s );
			for (int j = len; j >i; j--) newStr[j] = newStr[j - 1];
			newStr[i] = insert;
			newStr[len+1] = 0;
			int tempScore = 0, roundScore;
			while ((roundScore = eliminate( newStr )) != 0) tempScore += roundScore;
			if (tempScore>maxScore) maxScore = tempScore;
		}
	}
	return maxScore;
}

int main() {
	int t,l,rd,i;
	char ss[L];
	scanf("%d",&t);
	srand( (unsigned int)time(NULL) );
	while (t--) {
		memset(ss,0,L);
		ss[0] = '$';
		
		//scanf("%s",ss+1);
		l = rand()%10 + 1;
		for (i=1; i<=l; ++i) {
			rd = rand()%3;
			switch (rd) {
				case 0: ss[i]='A'; break;
				case 1: ss[i]='B'; break;
				case 2: ss[i]='C'; break;
			}
		}
		
		
		int a1 = ans1(ss);
		int a2 = ans2(ss+1);
		if (a1!=a2) {
			printf("%s\t%d\t%d\n",ss+1,a1,a2);
		}
	}
}
