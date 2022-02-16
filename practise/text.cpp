#include <iostream>
#include <math.h>
using namespace std;

void fun(int *arra, int n)
{

    int gap = n / 2;
    while (gap > 0)
    {

        for (int k = gap; k < n; k++)
        {
            int j = k;
            int curr = arra[k];
            while (j >= gap && curr < arra[j - gap])
            {
                /*imagine [...7...4...1........] this loop will compare
             4 with one and substitute 
            1 by 4 i.e. [7...4...4] and without replacing 4 for 1
             it will comapre 1 with 7 and save 7 at four pace[7....7....4] and 
             lastly after loop save 1 at 7's place [1....7....4....]
            */

                arra[j] = arra[j - gap];
                j -= gap;

                for (int k = 0; k < 10; k++)
                {
                    cout << arra[k] << " ,";
                }
                cout << endl;
            }
            arra[j] = curr;
        }
        cout << endl;

        gap = gap / 2;
        cout << " end of a gap loop " << endl;
    }

    // for (int k=0;k<10;k++){
    //     cout<<arra[k]<<" ,";
    // }
}

int main()
{
    int arra[10] = {10, 8, 4, 6, 2, 0, 5, 9, 3, 1};
    for (int k = 0; k < 10; k++)
    {
        cout << arra[k] << " ,";
    }
    cout << endl
         << endl
         << endl;
    fun(arra, 10);
}