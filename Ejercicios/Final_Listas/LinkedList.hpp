#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node
{
    int data;
    Node *next;
};

// Function declarations
void insertAtBeginning(Node *&head, int value);
void printList(Node *head);
void freeList(Node *&head);

#endif
