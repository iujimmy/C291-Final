#include "Defs.h"
#include "HelperFunctions.h"

// Recursive function to merge nodes of two sorted lists
// into a single sorted list
struct DoublyLinkedList* merge(struct DoublyLinkedList* a, struct DoublyLinkedList* b)
{
    // Base cases to return NULL
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    // Pick either a or b, and use recursion on them
    if (a->frequency >= b->frequency)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

// Function to sort a DoublyLinkedList using merge sort algorithm
void mergesort(struct DoublyLinkedList** head)
{
    // Base case: 0 or 1 DoublyLinkedList
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    // Split head into a and b sublists
    struct DoublyLinkedList* a = *head, *b = NULL;
    split(*head, &a, &b);

    // Recursively sort the sublists
    mergesort(&a);
    mergesort(&b);

    // Merge the two sorted lists
    *head = merge(a, b);
}
