#include <iostream>
#include <map>
using namespace std; 

map<string,int> cache; 
map<string,int>::iterator it;

int main() {
	int n,m,i,size=0;
	string web[20000],w;
	cin>>n>>m;
	int s = 0;
	for (i=0; i<n; ++i){
		cin>>w;
		web[i] = w;
		if (cache.find(w)!=cache.end() && cache[w]>=s && cache[w]<=i) {
			puts("Cache");
		} else {
			puts("Internet");
			size++;
			if (size>m) {
				s++;
				size--;
			}
		}
		cache[w] = i;
		while (cache[web[s]]!=s)
			s++;
	}
}
