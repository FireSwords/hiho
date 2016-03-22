#include <cstdio>

const int N = 1010;
int w,h,n;
int x1[N],y1[N],x2[N],y2[N];
int cover[N][N],corner[N][4],res[N],root[N];

int abs(int x) {
	return x>0 ? x:-x;
}

bool in(int x, int y, int i) {
	if (x<=x1[i]) return false;
	if (x>=x2[i]) return false;
	if (y<=y1[i]) return false;
	if (y>=y2[i]) return false;
	return true;
}


bool intersect(int a,int b) {
	/*int i,j;
	if (in(x1[a], y1[a], b)) return true;
	if (in(x1[a], y2[a], b)) return true;
	if (in(x2[a], y1[a], b)) return true;
	if (in(x2[a], y2[a], b)) return true;
	if (in(x1[b], y1[b], a)) return true;
	if (in(x1[b], y2[b], a)) return true;
	if (in(x2[b], y1[b], a)) return true;
	if (in(x2[b], y2[b], a)) return true;
	if (x1[a]==x1[b]&&x2[a]==x2[b]) {
		if (y1[a]>=y1[b]&&y1[a]<=y2[b]) return true;
		if (y1[b]>=y1[a]&&y1[b]<=y2[a]) return true;
	}
	if (y1[a]==y1[b]&&y2[a]==y2[b]) {
		if (x1[a]>=x1[b]&&x1[a]<=x2[b]) return true;
		if (x1[b]>=x1[a]&&x1[b]<=x2[a]) return true;
	}
	return false;*/
	float dx,dy,cx,cy;
	dx = abs(0.5*(x1[a]+x2[a])-0.5*(x1[b]+x2[b]));
	dy = abs(0.5*(y1[a]+y2[a])-0.5*(y1[b]+y2[b]));
	cx = 0.5*(x2[a]-x1[a]) + 0.5*(x2[b]-x1[b]);
	cy = 0.5*(y2[a]-y1[a]) + 0.5*(y2[b]-y1[b]);
	if (dx<cx && dy<cy)
		return true;
	return false;
}

void setcorner(int a,int b) {
	if (in(x1[b], y1[b], a)) corner[b][0]=1;
	if (in(x1[b], y2[b], a)) corner[b][1]=1;
	if (in(x2[b], y1[b], a)) corner[b][2]=1;
	if (in(x2[b], y2[b], a)) corner[b][3]=1;
}

void output() {
	int i,j;
	printf("\ncover:\n");
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j)
			printf("%d ",cover[i][j]);
		putchar('\n');
	}
	printf("\ncorner:\n");
	for (i=0; i<n; ++i) {
		for (j=0; j<4; ++j)
			printf("%d ",corner[i][j]);
		putchar('\n');
	}
	printf("\nres:\n");
	for (i=0; i<n; ++i)
		printf("%d ",res[i]);
	putchar('\n');
}

void on(int i) {
	int j;
	for (j=i+1; j<n; ++j)
		if (cover[i][j]) {
			flag[j] = 1;
			on(j);
		}
	int cnt=1;
	for (j=i+1; i<n; ++j)
		if (flag[j]) cnt++;
	res[j] = max(res[j],cnt);
}

int main() {
	int i,j;
	scanf("%d%d%d",&w,&h,&n);
	for (i=0; i<n; ++i) {
		for (j=0; j<n; ++j)
			cover[i][j] = 0;
		for (j=0; j<4; ++j)
			corner[i][j] = 0;
	}
	for (i=0; i<n; ++i) {
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		for (j=0; j<i; j++) {
			if (intersect(i,j))
				cover[j][i] = 1;
			setcorner(i,j);
		}
	}
	int ans=0, max=0;
	for (i=0; i<n; ++i) {
		if (corner[i][0]&&corner[i][1]&&corner[i][2]&&corner[i][3])
			continue;
		on(i);
		int cnt = 0;
		for (j=i+1; j<n; ++j)
		if (res[i]>=max) {
			max = res[i];
			ans = i;
		}
	}
	output();
	printf("%d %d\n",max,ans+1);
}
