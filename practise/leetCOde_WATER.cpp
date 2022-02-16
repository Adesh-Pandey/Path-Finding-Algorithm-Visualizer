#include <iostream>
using namespace std;
#include <vector>

int maxArea(int height[], int n)
{
    int i = 0, j = n - 1;
    int area = 0;
    while (i < j)
    {
        int length = min(height[i], height[j]);
        int breadth = abs(i - j);
        area = max(area, length * breadth);

        if (height[i] <= height[j])
        {
            i++;
        }
        else
            j--;
    }
    return area;
}

int main()

{

    int n, x;
    cin >> n;
    int height[n];
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << maxArea(height, n);
}