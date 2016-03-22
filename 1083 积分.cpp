#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 8005;
const double PI = acos(-1);
struct point {
	int x,y;
};
point p[N];

double f(double k,double b,int x) {
    double sum = 0.0;
	sum += (k+k*k/2)/3 * pow(x,3);
	sum += (k*b+b)/2 * pow(x,2);
	sum += b*b/2 * x;
    return sum;
}

double f0(double k,double b,int x) {
	return 0.5*k*pow(x,2)+b*x;
}

int main() {
	int t,n,i,j;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (i=0; i<n; ++i)
			scanf("%d%d",&(p[i].x),&(p[i].y));
		p[n]=p[0];

		//ÇóºÍ
		int xi,yi,xj,yj;
		double k,b,ans=0.0,area=0.0;
		for (i=0; i<n; ++i) {
			j = i+1;
			xi=p[i].x; yi=p[i].y;
			xj=p[j].x; yj=p[j].y;
			if (xj==xi) continue;
			k = double(yj-yi)/(xj-xi);
			b = yi - k * xi;
			ans += f(k,b,xj) - f(k,b,xi);
			area += f0(k,b,xj) - f0(k,b,xi);
		}
		if (area<0) ans=-ans;
		if (fabs(ans)<1e-4) ans=0.0;
		printf("%.2lf\n",ans);
	}
}
