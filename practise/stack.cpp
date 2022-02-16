#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int first = 0;
        int sec = 0;
        int merge = 0;
        int newArrLen = nums1.size() + nums2.size();
        int arr[newArrLen];

        while (first < nums1.size() && sec < nums2.size())
        {
            if (nums1[first] < nums2[sec])
            {
                arr[merge++] = nums1[first++];
            }
            else
            {
                arr[merge++] = nums2[sec++];
            }
        }

        while (first < nums1.size())
        {
            arr[merge++] = nums1[first++];
        }
        while (sec < nums2.size())
        {
            arr[merge++] = nums2[sec++];
        }

        if (newArrLen % 2 == 1)
        {
            return arr[(newArrLen - 1) / 2];
        }
        else
        {
            int n = newArrLen / 2;
            return (float((arr[n - 1] + arr[n])) / 2);
        }
    }
};

int main()
{
    Solution s;
    int n, r;
    vector<int> nums1, nums2;
    cin >> n >> r;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        nums1.push_back(tmp);
    }
    for (int i = 0; i < r; i++)
    {
        cin >> tmp;
        nums2.push_back(tmp);
    }
    cout << s.findMedianSortedArrays(nums1, nums2);
}