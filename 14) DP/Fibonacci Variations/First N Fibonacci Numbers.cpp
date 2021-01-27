// First n Fibonacci Numbers

#include <bits/stdc++.h>
using namespace std;
vector<long long> printFibb(int);

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;

        vector<long long> ans = printFibb(n);
    
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

vector<long long> printFibb(int n) {
    vector<long long int>f(n);
    f[0]=1;
    f[1]=1;
    for(int i=2;i<n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
    return f;    
}