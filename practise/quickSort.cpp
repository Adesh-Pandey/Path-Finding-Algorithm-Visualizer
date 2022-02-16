#include <iostream>
using namespace std;

int n = 5;

void QuickSort(int *Arr, int pivotIndx, int startIndx)
{
    if (pivotIndx == startIndx || startIndx < 0 || startIndx >= n || pivotIndx <= 0 || pivotIndx >= n || pivotIndx < startIndx)
    {
        return;
    }

    int stableIndx = startIndx;
    for (int loop = startIndx; loop < pivotIndx; loop++)
    {
        if (Arr[loop] <= Arr[pivotIndx])
        {
            swap(Arr[loop], Arr[stableIndx]);
            stableIndx++;
        }
    }
    swap(Arr[pivotIndx], Arr[stableIndx]);
    bool flag = true;
    QuickSort(Arr, stableIndx - 1, 0);

    QuickSort(Arr, n - 1, stableIndx + 1);
}

int main()
{

    int *Arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    QuickSort(Arr, 4, 0);

    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << ", ";
    }
}
