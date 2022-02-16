#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtLast(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void printList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int length(node *head)
{
    node *tmp = head;
    int counter = 0;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        counter++;
    }
    return counter;
}

void insertAtFirst(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void search(node *head, int val)
{

    node *tmp = head;
    int counter = 0;
    while (head != NULL)
    {

        if (tmp->data == val)
        {
            cout << endl
                 << "Element at " << val << " Found" << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Element Not Found";
}

void removeNode(node *&head, int val)
{
    node *tmp = head;
    node *prev = head;
    if (head->data == val)
    {
        node *n = head;
        head = head->next;
        return;
    }
    while (tmp != NULL)
    {

        if (tmp->data == val)
        {
            prev->next = tmp->next;
            delete tmp;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

node *_reverse(node *&now, node *&prev)
{

    if (now == NULL)
    {
        return prev;
    }
    node *next = now->next;

    now->next = prev;
    prev = now;

    _reverse(next, prev);
}
void reverse(node *&head)
{
    node *prev = NULL;
    node *tmp = head;
    head = _reverse(tmp, prev);
}

node *removeHead(node *&head)
{
    node *n = head->next;
    delete head;
    return n;
}

bool hasCycle(node *head)
{

    node *traveller = head->next;
    vector<node *> addresses;
    addresses.push_back(head);
    while (traveller != NULL)
    {
        for (auto i = addresses.begin(); i < addresses.end(); i++)
        {
            if (traveller == *i)
            {
                return true;
            }
        }

        addresses.push_back(traveller);
        traveller = traveller->next;
    }
    return false;
}

void removeFromLast(node *&head)
{

    node *tmp = head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    delete (tmp->next);
    tmp->next = NULL;
}

node *reverseTillKthNode(node *&head, int k)
{

    node *prev = NULL;
    node *tmp = head;
    node *next = head;
    int counter = 0;
    while (true)
    {
        if (++counter == k)
        {
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            goto end;
        }

        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
end:

    head->next = next;
    head = prev;
    return head;
}
void alterKReverse(node *&head, int k)
{
    int counter = 0;
    int scounter = 0;
    node *n = head;
    node *endd = NULL;

    while (length(n) >= k)
    {
        n = reverseTillKthNode(n, k);

        if (++counter == 1)
        {
            head = n;
        }
        else
        {
            endd->next = n;
        }

        scounter = 0;
        while (++scounter < k)
        {
            n = n->next;
        }
        endd = n;
        n = n->next;
    }
}
void makeCycle(node *&head)
{
    node *tmp = head;
    int counter = 0;
    while (tmp->next != NULL)
    {
        if (counter == 5)
        {
            break;
        }
        counter++;
        tmp = tmp->next;
    }
    node *tmpEnd = head;
    while (tmpEnd->next != NULL)
    {

        tmpEnd = tmpEnd->next;
    }
    tmpEnd->next = tmp;
}
node *hasCycleFLoyds(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return fast;
        }
    }
    return NULL;
}

void removeLoop(node *&head)
{
    node *slow = hasCycleFLoyds(head);
    if (slow == NULL)
    {
        cout << "NO LOOP TO DELETE" << endl;
        return;
    }
    node *fast = head;
    node *tmp = head;
    while (fast != slow)
    {
        tmp = slow;
        fast = fast->next;
        slow = slow->next;
    }

    tmp->next = NULL;
}

int main()
{
    node *head = NULL;
    insertAtLast(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    insertAtLast(head, 4);
    insertAtLast(head, 5);
    insertAtFirst(head, 0);
    insertAtLast(head, 7);
    insertAtLast(head, 8);
    insertAtLast(head, 9);
    insertAtFirst(head, 10);

    //floyds algogrithm alternative : o(n2). brute force approach;
    //floyds algo

    printList(head);
    reverse(head);
    printList(head);
    makeCycle(head);
    cout << hasCycle(head) << endl;
    removeLoop(head);
    cout << hasCycle(head);

   

    return 0;
}