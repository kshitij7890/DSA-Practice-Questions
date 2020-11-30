#include <iostream>
using namespace std;


void func(string s,int l,int r)
{
    if(l==r)
    {
        cout<<s<<" ";
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
           swap(s[l],s[i]);
           func(s,l+1,r);
           swap(s[l],s[i]);
        }

    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    func(s,0,s.length()-1);
	    cout<<endl;
	    
	    
	}
	return 0;
}