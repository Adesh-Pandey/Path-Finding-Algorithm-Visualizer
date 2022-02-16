#include <iostream>
using namespace std;
#include <queue>

bool visit(int visited[])
{
    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int minimumUnvisited(int visited[], int shot[])
{
    int mini = INT_MAX;
    int index = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == 0)
        {
            if (mini > shot[i])
            {
                mini = shot[i];
                index = i;
            }
        }
    }
    return index;
}

int main()
{

    int G[5][5] = {
        {-1, 2, 5, 1, -1},
        {2, -1, 7, 6, 13},
        {5, 7, -1, 3, -1},
        {1, 6, 3, -1, 12},
        {1, 13, -1, 12, -1}};

    int vertices[] = {1, 2, 3, 4, 5};
    int shortFromStart[] = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    int prev[] = {0, 0, 0, 0, 0};
    int visited[] = {0, 0, 0, 0, 0};
    int node;

    while (visit(visited))
    {

        int ans = minimumUnvisited(visited, shortFromStart);

        if (ans == INT_MAX)
            break;
        node = vertices[ans];

        for (int i = 0; i < 5; i++)
        {
            if (G[ans][i] != -1)
            {
                if (shortFromStart[i] > shortFromStart[ans] + G[ans][i])
                {
                    shortFromStart[i] = shortFromStart[ans] + G[ans][i];
                    prev[i] = vertices[ans];
                }
            }
        }
        visited[ans] = 1;
    }
    cout << shortFromStart[3] << " " << prev[4];
}

// queue<int> BFS;

// BFS.push(1);
// visited[0] = 1;

// while (!BFS.empty())
// {

//     int node = BFS.front();
//     BFS.pop();
//     cout << node << " ";

//     for (int i = 0; i < 5; i++)
//     {
//         if (G[node - 1][i] != 0 && visited[i] == 0)
//         {
//             BFS.push(vertices[i]);
//             visited[i] = 1;
//         }
//     };
// }