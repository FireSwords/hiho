#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int L = 2200;
struct Match {
	int p1,p2,len;
	Match(int a,int b,int l) {
		p1=a; p2=b; len=l;
	}
};

int process(vector<Match*> h0) {
	if (!h0.size()) return 0;
	int l1,l2;
	Match* a = h0.back();
	h0.pop_back();
	l1 = process(h0);
	
	vector<Match*> h1;
	vector<Match*>::iterator it;
	int ap1=a->p1, ap2=a->p2;
	for (it=h0.begin(); it!=h0.end(); ++it) {
		Match* e = *it;
		int p1=e->p1, p2=e->p2, l=e->len;
		if (p1+l<=ap1 && p2+l<=ap2)
			h1.push_back(e);
	}
	l2 = process(h1) + a->len;
	return (l1>l2)?l1:l2;
}

int main() {
	char str1[L],str2[L];
	int l1,l2;
	scanf("%s",str1); l1=strlen(str1);
	scanf("%s",str2); l2=strlen(str2);
	if (l1>l2) {
		swap(str1,str2); swap(l1,l2);
	}
	
	vector<Match*> h;
	int i=0,j,cnt;
	while(i<=l1-3) {
		j = 0;
		while (j<=l2-3) {
			cnt = 3;
			if (!strncmp(str1+i,str2+j,cnt)) {
				while(i+cnt<l1 && j+cnt<l2 && str1[i+cnt]==str2[j+cnt]) 
					cnt++;
				h.push_back(new Match(i,j,cnt));
			}
			j++;
		}
		i++;
	}
	
	printf("%d\n",process(h));
}
