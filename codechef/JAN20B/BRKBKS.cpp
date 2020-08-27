#include <cstdio>

using namespace std;

int main() {
	int T, S, W1, W2, W3;
	int temp, left, right, tot;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d %d",&S,&W1,&W2,&W3);
		left = W1+W2;
		right = W3+W2;
		tot = W1+W2+W3;

		if(S>=tot) printf("%d\n",1);
		else if(S>=left) printf("%d\n",2);
		else if(S>=right) printf("%d\n",2);
		else printf("%d\n",3);
	}
	return 0;
}