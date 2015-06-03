#include<cstdio>
#include<map>
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	int cnt=0;
	map<string,int>mp;
	map<string,int>::iterator it;
	pair<map<string,int>::iterator,bool> ret;
	while(getline(cin,str)) {
		cnt++;
		ret=mp.insert(pair<string,int>(str,1));
		if(ret.second==false) {
			(ret.first)->second++;
		}
	}
	for(it=mp.begin();it!=mp.end();++it) {
		printf("%s %.4lf\n",(it->first).c_str(),100*(it->second)/(double)cnt);
	}
	return 0;
}
