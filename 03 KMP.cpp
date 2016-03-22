#include <cstdio>
#include <cstring>
#include <malloc.h>

char pattern[10005], str[1000005];

int matchLength(char* s, char* p) {
	int l=0;
	while ((s[0]==p[0])and(s[0])) {
		++l;
		++s, ++p;
	}
	return l;
}

int subMatchPos(char* p, char* np, int nml) {
	int pl = strlen(p);
	int i,j;
	for (i=pl; i>0; i--) {
		bool flag = true;
		char* pp = p+i;
		for (j=0; j<nml; j++)
			if (pp[j]!=np[j]) {
				flag = false;
				break;
			}
		if (flag) 
			return i;
	}
	return 0;
}

char* next(char*s, char*p, int ml) {
	int pl, nml;
	pl = strlen(p);
	nml = pl - ml;
	if ((nml==0)||(nml==pl))
		return s+1;
	else {		
		char* nms = (char*)malloc(nml+1);
		strncpy(nms, s+ml, nml);
		nms[nml] = '\0'; 
		int pos = subMatchPos(p, nms, nml);
		return s+ml-pos;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int cnt=0, ml, l, pl;
		scanf("%s", pattern);
		scanf("%s", str);
		char* s = str;
		char* p = pattern;
		l = strlen(s);
		pl = strlen(p);
		while (l>=pl) {
			ml = matchLength(s, p);
			if (ml==pl) ++cnt;
			s = next(s, p, ml);
			//printf("s = %s\n", s);
			l = strlen(s);
		}
		printf("%d\n", cnt);
	}	
}
