#include<vector>
#include<cstdio>
const int md = (int)1e9 + 7;
struct matrix // A matrix class
{
vector <vector <int> > mat;
matrix(int n = 0, bool id = false)
{
mat.resize(n);
for (int i = 0; i < n; i++) mat[i].resize(n);
if (id) for (int i = 0; i < n; i++) mat[i][i] = 1;
}
inline int size() { return (int)mat.size(); }
vector <int>& operator[] (int i) { return mat[i]; }
};
matrix operator * (matrix &a, matrix &b) // Multiplies two matrices
{
int n = a.size();
matrix ret(n);
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
for (int k = 0; k < n; k++)
{
ret[i][j] += 1ll * a[i][k] * b[k][j] % md;
if (ret[i][j] >= md) ret[i][j] -= md;
}
return ret;
}
matrix pow(matrix &a, long long p) // Matrix exponentiation through repeated squaring
{
int n = a.size();
matrix ret(n, true);
while (p > 0)
{
if (p % 2 == 1) ret = ret * a;
p /= 2, a = a * a;
}
return ret;
}
matrix base() //Builds the base matrix that is to be exponentiated
{
matrix ret(15);

return ret;
}
int main() {
	unsigned ll N,K;
	unsigned ll arr[116];
	int brick[16];
	var(unsigned ll);
	fr(i,0,16)
		brick[i]=0;
	fr(i,0,116)
		arr[i]=0;
	sc("%llu",&N);
	sc("%llu",&K);
	fr(i,0,K) {
		sc("%llu",&tmp);
		brick[tmp]+=1;
	}
	fr(i,101,116) {
		fr(j,1,16) {
			arr[i]+=(arr[i-j]*brick[j]);
		}
		arr[i]+=brick[i-100];
	}
	if(N<=15)
		pf("%llu\n",arr[100+N]);
	else {
		
	
	}
	return 0;
}
