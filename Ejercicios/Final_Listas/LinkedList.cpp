#include "LinkedList.hpp"
#include <iostream>
using namespace std;

void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void freeList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
