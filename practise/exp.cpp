#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// class Solution
// {
// public:
//     bool isRectangleCover(vector<vector<int>> &rectangles)
//     {

//         vector<float> slope;
//         int slopeOfOne;
//         int trueArea = 0, length, breadth, calcArea;
//         int lowX = INT_MAX, lowY = INT_MAX, highX = INT_MIN, highY = INT_MIN;
//         int fx1, fy1, fy2, fx2, vx1, vx2, vy1, vy2;
//         float xb, yb;

//         for (int i = 0; i < rectangles.size(); i++)
//         {
//             slopeOfOne = float(rectangles[i][3] - rectangles[i][1]) / float((rectangles[i][2] - rectangles[i][0]));
//             slope.push_back(slopeOfOne);
//         }

//         for (int mainIt = 0; mainIt < rectangles.size(); mainIt++)
//         {
//             fx1 = rectangles[mainIt][0];
//             fy1 = rectangles[mainIt][1];
//             fx2 = rectangles[mainIt][2];
//             fy2 = rectangles[mainIt][3];

//             for (int secondaryIt = mainIt; secondaryIt < rectangles.size() - 1; secondaryIt++)
//             {

//                 vx1 = rectangles[secondaryIt][0];
//                 vy1 = rectangles[secondaryIt][1];
//                 vx2 = rectangles[secondaryIt][2];
//                 vy2 = rectangles[secondaryIt][3];

//                 if (((vx1 < fx2 && vx1 > fx1) && (vy1 < fy2 && vy1 > fy1)) || ((vx2 < fx2 && vx2 > fx1) && (vy2 < fy2 && vy2 > fy1)))
//                 {
//                     return false;
//                 }
//                 if (((fx1 < vx2 && fx1 > vx1) && (fy1 < vy2 && fy1 > vy1)) || ((fx2 < vx2 && fx2 > vx1) && (fy2 < vy2 && fy2 > vy1)))
//                 {
//                     return false;
//                 }
//                 else
//                 {
//                     if (slope[secondaryIt] == slope[mainIt])
//                     {
//                         continue;
//                     }
//                     xb = (float(vy1) - float(fy1) - slope[secondaryIt] * float(vx1) + fx1 * slope[mainIt]) / (slope[mainIt] + slope[secondaryIt]);
//                     yb = float(vy2) - slope[secondaryIt] * (float(vx2) - xb);
//                     cout << " (" << xb << "," << yb << ") ";

//                     if (xb < 0 or yb < 0)
//                     {
//                         continue;
//                     }

//                     if (((xb < fx2 && xb > fx1) && (yb < fy2 && yb > fy1)) && ((xb < vx2 && xb > vx1) && (yb < vy2 && yb > vy1)))
//                     {
//                         return false;
//                     }
//                 }
//             }
//         }
//         for (int i = 0; i < rectangles.size(); i++)
//         {
//             length = (rectangles[i][2] - rectangles[i][0]);
//             breadth = (rectangles[i][3] - rectangles[i][1]);
//             if (length < 0)
//             {
//                 length = -1 * length;
//             }
//             if (breadth < 0)
//             {
//                 breadth = -1 * breadth;
//             }
//             trueArea += length * breadth;
//             // for left bottom point

//             if (rectangles[i][0] < lowX)
//             {
//                 lowX = rectangles[i][0];
//                 lowY = rectangles[i][1];
//             }
//             else if (rectangles[i][0] == lowX)
//             {
//                 if (rectangles[i][1] < lowY)
//                 {
//                     lowX = rectangles[i][0];
//                     lowY = rectangles[i][1];
//                 }
//             }
//             //for top right point
//             if (rectangles[i][3] > highY)
//             {
//                 highX = rectangles[i][2];
//                 highY = rectangles[i][3];
//             }
//             else if (rectangles[i][3] == highY)
//             {
//                 if (rectangles[i][2] > highX)
//                 {
//                     highX = rectangles[i][2];
//                     highY = rectangles[i][3];
//                 }
//             }
//         }
//         calcArea = (highX - lowX) * (highY - lowY);
//         cout << highX << " " << highY << " " << lowX << " " << lowY << " cal" << calcArea << " true" << trueArea;

//         if (calcArea == trueArea)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

int main()
{
    float w = 25;
    float x = 1.0 / 2.0;
    w = pow(w, x);
    cout << w << x;

    for (int i = 0; i < rectangles.size(); i++)
    {
        fx1 = rectangles[i][0];
        fy1 = rectangles[i][1];
        fx2 = rectangles[i][2];
        fy2 = rectangles[i][3];
        for (int j = i; j < rectangles.size() - 1; j++)
        {

            vx1 = rectangles[j][0];
            vy1 = rectangles[j][1];
            vx2 = rectangles[j][2];
            vy2 = rectangles[j][3];

            if (fx1 < vx2 && fy1 < vy2 && vy1 < fy2 && vx1 < fx2)
            {
                return false;
            }
        }
    }
}