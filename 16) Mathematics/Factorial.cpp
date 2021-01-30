#include <bits/stdc++.h>
using namespace std;

long long factorial (int N)
{   
    if(N>1)
    {
        return N*factorial(N-1);
    }
    else return 1;
    
}

int main()
{
    int T,N;
    cin>>T;  
    while(T--)
    {
        cin>>N;
        cout<<factorial(N)<<endl;
    }
    return 0;
}