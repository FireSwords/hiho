#include <cstdio>
#include <cstring>

const int L = 10*1024*1024+100;
char str[L];
int n,l;

bool judge() {
	int i,j,k,cnt;
	i = 0;
	while (i<=l-3) {
		char ch = str[i];
		j=i+1; cnt=1;
		while(j<l && str[j]==str[i])
			j++, cnt++;
		if (j+cnt*2<=l) {
			bool flag = true;
			for (k=j; k<j+cnt; k++) {
				if (str[k]!=ch+1 || str[k+cnt]!=ch+2) {
					flag=false; 
					//printf("%d:%c %d:%c %d\n",k,str[k],k+cnt,str[k+cnt],flag);
					break;
				}
			}
			if (flag) return true;
		}
		i++;
	}
	return false;
}

int main() {
	printf("%d\n",L);
	scanf("%d",&n);
	while (n--) {
		scanf("%d",&l);
		scanf("%s",str);
		if (judge()) puts("YES");
		else puts("NO");
	}
}
