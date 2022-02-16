#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{

    vector<int> value(nums.size(), INT_MAX);
    value[0] = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (i <= k + nums[k])
                value[i] = min(value[k] + 1, value[i]);
        }
    }

    return value[nums.size() - 1];
}

bool goToZero(vector<int> &nums, int pos, vector<int> &visited)
{
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> tempVisited = visited;
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] + k < nums.size())
                tempVisited[k] = tempVisited[k] || tempVisited[nums[k] + k];

            if (k - nums[k] > -1)
                tempVisited[k] = tempVisited[k] || tempVisited[k - nums[k]];
        }

        if (visited == tempVisited)
        {
            return visited[pos];
        }
        visited = tempVisited;
    }
    return visited[pos];
}

int main()
{
    // vector<int> nums = {2, 9, 6, 5, 7, 0, 7, 2, 7, 9, 3, 2, 2, 5, 7, 8, 1, 6, 6, 6, 3, 5, 2, 2, 6, 3};
    // cout << jump(nums);
    vector<int> nums = {4, 2, 3, 0, 3, 1, 2};
    vector<int> visited;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            visited.push_back(1);
        else
            visited.push_back(0);
    }

    cout << goToZero(nums, 5, visited);
}
/*
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
*/