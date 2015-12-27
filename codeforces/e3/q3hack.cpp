#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, b = 0, sr;
    cin >> n;
    long long res = 0, su = 0;
    vector <int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        su += a[i];
    }

    sr = su / n;
    b = su % n;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > sr)
        {
            if (b > 0)
            {
                --b;
                res += a[i] - sr - 1;
            }
            else
                res += a[i] - sr;
        }
        /*else
            res += sr - a[i];*/
    }

    cout << res;
}