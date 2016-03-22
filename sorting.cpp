#include <vector>
#include <iostream> 
using namespace std;

typedef pair<int,int> pii;
const int N = 10;
int from[N] = {0};
int to[N] = {0};
int weight[N] = {0};

int main(void) 
{
	int i;
	vector<pii> keys(N);
	for (i=0; i<N; ++i)
		keys[i] = pii(from[i], to[i]);
	vector<int> values(N);
	values.assign(weight, weight+N);

	
	printf("f:");
	for (i=0; i<N; ++i)
		printf(" %d",(keys[i]).first);
	printf("\nt:");
	for (i=0; i<N; ++i)
		printf(" %d",(keys[i]).second);
	printf("w:");
	for (i=0; i<N; ++i)
		printf("%d ",values[i]);

}
