#include <stdio.h>
#include <conio.h>

void main()
{

    int n1, n2, n3, greatest;

    printf("enter 5 numbers ");
    scanf("%d%d%d", n1, n2, n3);

    if (n1 > n2 && n1 > n3)
    {
        greatest = n1;
    }
    else if (n2 > n3)
    {
        greatest = n2;
    }
    else
    {
        greatest = n3;
    }

    printf("among %d %d%d , %d is the greatest", n1, n2, n3, greatest);
    getch();
}