#include<bits/stdc++.h>
using namespace std;

bool isPrime(int N)
{
    bool is_prime = true;
    for(int i=2;i<=N/2;i++)
    {
        if(N%i == 0)
        {
            is_prime=false;
            break;
        }
    }
    return is_prime;
}

int main()
{
    int T; 
    cin>>T; 
    while(T--) 
    {
        int N;
        cin>>N; 
        
        if(isPrime(N)) 
        cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}