#include <iostream>
using namespace std;

void string_reverse(string s)
{
    int len=s.length();
    int start=0;
    int end=len-1;
    while(start<end)
    {
        swap(s[start],s[end]);
        start++;
        end--;
    }
    for(int i=0;i<len;i++)
	    {
	        cout<<s[i];
	    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    string_reverse(s);
	    cout<<endl;
	}
	return 0;
}
