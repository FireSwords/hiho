#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

void sort(int x,int y,int z,int *s) {
	if (x>y) swap(x,y);
	if (x>z) swap(x,z);
	if (y>z) swap(y,z);
	s[0]=x; s[1]=y; s[2]=z;
}

int main() {
	int x,y,z,cr,cy,cb,s1[3],s2[3];
	char seq[20010];
	scanf("%d%d%d",&x,&y,&z);
	scanf("%s",seq);
	int len = strlen(seq);
	sort(x,y,z,s1);
	if (s1[2]-s1[1]!=s1[0]) {
		printf("%d\n",len);
		return 0;
	}
	
	cr = cy = cb = 0;
	int i, remain=0, ans=0;
	for (i=0; i<strlen(seq); ++i) {
		remain++;
		ans = max(ans, remain);
		switch(seq[i]) {
			case 'R': cr++; break;
			case 'Y': cy++; break;
			case 'B': cb++; break;
			default: return -1;
		}
		sort(fabs(cr-cy),fabs(cr-cb),fabs(cb-cy),s2);
		if (s2[0]==s1[0] && s2[2]==s1[2]) {
			remain -= (cr+cy+cb);
			cr=cy=cb=0;
		}
	}
	printf("%d\n",ans);
}
