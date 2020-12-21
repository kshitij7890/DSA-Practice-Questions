#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> arr(256, 0);
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 1)
            cout << (char)i << " ";
    }
    return 0;
}