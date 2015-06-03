#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<sstream>
using namespace std;
int main () {
  int c=0,i;
  string line;
  long long sum,temp;
  for(i=4;i>=0;i--) {
  	sum=0;
  	ifstream myfile ("in.txt");
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
		  //cout<<line<<'\n';
		  stringstream(line.substr(i*10,10).c_str())>>temp;
		  sum+=temp;
		  //cout<<line.substr(0,10).c_str()<<endl;
		}
		sum+=c;
		c=sum/10000000000;
		myfile.close();
	}
  }
  printf("%lld",sum);
  return 0;
}
