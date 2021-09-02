#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    //code
    long long t;
    cin >> t;
    while (t--)
    {
        long long l, n;
        cin >> l >> n;
        vector<long long> arr(l);
        long long flag = 0;
        unordered_set<long long> s;
        for (long long i = 0; i < l; i++)
        {
            cin >> arr[i];
        }

        for (long long i = 0; i < l; i++)
        {
            if (s.find(n + arr[i]) != s.end() || s.find(arr[i] - n) != s.end())
            {
                flag = 1;
                cout << "1" << endl;
            }
            s.insert(arr[i]);
        }

        if (flag == 0)
            cout << "-1" << endl;
    }
    return 0;
}