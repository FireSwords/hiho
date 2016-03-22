#include <cstdio>
#include <cstring>

const int N = 220;
const char s1[] = "marshtomp";
const char s2[] = "fjxmlhx";
const int slen = strlen(s1);
char str[N];

int main() {
	int i,p,len,pos;
	char tmp[] = "marshtomp";
	while(gets(str)) {
		len = strlen(str);
		p = 0;
		while (p<len) {
			memcpy(tmp,str+p,slen);
			for (i=0; i<slen; ++i)
				if (tmp[i]>='A'&& tmp[i]<='Z')
					tmp[i] = tmp[i]-'A'+'a';
			if (!strcmp(s1,tmp)) {
				printf("%s",s2);
				p += slen;
			}
			else {
				printf("%c",str[p]);
				p++;
			}
		}
		putchar('\n');
	}
}
