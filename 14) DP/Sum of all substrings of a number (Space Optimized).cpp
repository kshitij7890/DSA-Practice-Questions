// SPACE OPTIMIZED CODE FOR SUM OF ALL SUBSTRINGS QUESTION
// AUX SPACE : O(1)


long long toDigit(char ch)
{
    return (ch - '0');
}

long long sumSubstrings(string s)
{
    long long mod=1e9+7;
    long long prev = toDigit(s[0]);
    long long res= prev;
    long long curr=0;
    
    for(int i=1;i<s.length();i++)
    {   
        curr=(((i+1)*toDigit(s[i]))+(10*(prev%mod)))%mod;
        res=(res%mod)+(curr%mod);
        prev=curr;
    }
    
    return res%mod;
}