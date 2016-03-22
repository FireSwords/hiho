#include <iostream>
#include <string>
using namespace std;

string post(string pre, string mid) {
	if (pre.length()<2)
		return pre;
	size_t pos = mid.find(pre[0]);
	return post(pre.substr(1,pos), mid.substr(0,pos-1)) + post(pre.substr(pos+1), mid.substr(pos+1)) + pre[0];
}

int main() {
	string pre,mid;
	cin>>pre>>mid;
	cout<<post(pre,mid)<<endl;
	return 0;
}
