#include <iostream>
#include <math.h>
using namespace std;

int bin(int n)
{
    int copyNum = n;
    int lastDigit;
    int binNum = 0;
    int counter = 0;
    while (copyNum != 0)
    {

        lastDigit = copyNum % 10;
        binNum = ((binNum) | ((lastDigit) << counter));
        copyNum = copyNum / 10;
        counter++;
    }
    return binNum;
}

int finalConvert(int num)
{

    int val = 0;

    int final = 0;
    for (int i = 0; i < 32; i++)
    {

        val = (num & (1 << i));
        if (val)
        {
            val = 1;
        }
        else
        {
            val = 0;
        }
        final += (pow(10, i) * val);
    }
    return final;
}

int main()
{
    int n1, n2;

    cin >> n1 >> n2;
    cout << finalConvert(bin(n1) + bin(n2));
}