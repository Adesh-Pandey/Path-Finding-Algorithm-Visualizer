#include <iostream>
using namespace std;

int main()
{

    class Node
    {
    public:
        int data;
        Node *next;

        void printt(Node n)
        {

            cout << (n).data << " ";
            if (n.next)
            {
                printt(*(n.next));
            }
        };
        void PrintRemaining()
        {
            cout << data << " ";
            printt(*next);
        }
    };
    Node A, B, C;
    A.data = 1;
    B.data = 2;
    C.data = 3;
    A.next = &B;
    B.next = &C;
    C.next = NULL;

    // cout << A.data << " " << (*A.next).data;
    B.PrintRemaining();
}