/*
ID: vedsarkushwaha
PROG: test
LANG: C++                  (<-- or C++11f you prefer)
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}