#include <bits/stdc++.h>
using namespace std;

int absolute(int I);

int main() {
    int T;    
    cin >> T; 
    while (T--) {
        int I;
        cin >> I;
        cout << absolute(I) << endl;
    }
    return 0;
}

int absolute(int I) {
    return abs(I);
}