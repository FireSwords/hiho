#include <cstdio>

int abs(int x) {
	return x>0? x:-x;
}

int main() {
	int q,m,n;
	int x0,y0,lastx,lasty,curtx,curty,dx,dy,i;
	scanf("%d",&q);
	
	while(q--) {
		scanf("%d%d",&n,&m);
		scanf("%d%d",&x0,&y0);
		lastx=x0; lasty=y0;
		bool flag = true;
		for (i=0; i<n-1; ++i) {
			scanf("%d%d",&curtx,&curty);
			dx = abs(curtx-lastx);
			dy = abs(curty-lasty);
			if (dx+dy<m)
				flag = false;
			lastx = curtx;
			lasty = curty;
		}
		dx = abs(x0-lastx);
		dy = abs(y0-lasty);
		if (dx+dy<m)
			flag = false;

		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
