#include <cstdio>
#include <cmath>

int a,b,c,x,y;

float dist(float x0) {
	float y0 = a*x0*x0 + b*x0 + c;
	return (pow(x-x0,2)+pow(y-y0,2));
}

float conquer(float l,float r) {
	if (r-l<0.0001) return l;
	float lm = (r-l)/3 + l;
	float rm = r - (r-l)/3;
	if (dist(lm)<dist(rm))
		return conquer(l,rm);
	else
		return conquer(lm,r);
}

int main() {
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	float axis=-b/(a*2.0),l,r;
	if ((float)x<axis) {l=-200; r=axis;}
	else {l=axis; r=200;}
	float x0 = conquer(l,r);
	printf("%.3f", sqrt(dist(x0)));
}
