#include <bits/stdc++.h>
using namespace std;

long long int digitsInFactorial(int N)
{
    double zz = 0; // double will come always as decimals are required
    for (int i = 2; i <= N; i++)
    {
        zz = zz + log10(i);
    }
    return (floor(zz) + 1);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << digitsInFactorial(N) << endl;
    }
    return 0;
}