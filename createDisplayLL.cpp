#include <iostream>

using namespace std;

struct Node
{
    int data;          // data member
    struct Node *next; // Que: What's meaning of this line? Ans: A pointer to its self-referential pointer. Structure which includes at least one member that is a pointer to the structure of its own kind.
} *first = NULL;       // global pointer

// Create function
void create(int A[], int n) // A[] is array and n is size of array
{
    struct Node *t, *last;
    first = new Node;   // create first node in LL
    first->data = A[0]; // Que: Why -> and .? Ans: To access memebers of a structure, use the dot operator. To access members of a struture through a pointer, use the arrow operator.
    first->next = NULL; // first doesn't have any next node so NULL
    last = first;       // last also point to first

    for (int i = 1; i < n; i++)
    {
        t = new Node;   // Create a new node for temp 't'
        t->data = A[i]; // temp 't' var contain data
        t->next = NULL; // temp 't' next NULL
        last->next = t; // last next point to t
        last = t;       // last on t
    }
}

void Display(struct Node *p) // Que: whey it take *p? Ans: Pointing first pointer
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(Node *p) // Recursive Display Function
{
    if (p != NULL)
    {
        cout << p->data << " "; // Calling time | Ascending Order
        RDisplay(p->next);
        // cout << p->data << " "; // Returning time | Descending Order
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A) / sizeof(A[0]);
    create(A, size);
    Display(first);
    RDisplay(first);

    return 0;
}
