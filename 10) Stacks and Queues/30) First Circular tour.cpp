/*

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).

Expected Time Complexity: O(N)
Expected Auxiliary Space : O(N) (Here it will be O(1))

*/

#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump[], int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n) << endl;
    }
}

int tour(petrolPump p[], int n)
{
    int start = 0, end = 1;
    int curr = p[start].petrol - p[start].distance;
    while (start != end || curr < 0) // loop stops only when start=end and curr>=0
    {
        while (start != end && curr < 0)
        {
            curr -= p[start].petrol - p[start].distance;
            start = (start + 1) % n;

            if (start == 0)
                return -1;
        }

        curr = curr + (p[end].petrol - p[end].distance);
        end = (end + 1) % n;
    }

    return start;
}