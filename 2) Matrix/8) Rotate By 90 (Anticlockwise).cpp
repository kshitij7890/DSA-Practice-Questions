//ANTICLOCKWISE ROTATE
//TC : O(N^2)
//AS : O(1)

#include <bits/stdc++.h>
using namespace std;
#define N 105

int swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void rotateby90(int n, int arr[][N])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(&arr[start][j], &arr[end][j]);
            start++;
            end--;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[N][N], i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        rotateby90(n, a);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}