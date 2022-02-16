#include <iostream>
using namespace std;

int main()
{
    int b = 5;
    int *p = &b;
    cout << p << " " << *p << " " << &p;
}