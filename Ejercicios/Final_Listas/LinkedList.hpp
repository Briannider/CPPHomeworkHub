#include <iostream>
using namespace std;
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node{
    int value;
    Node* next;
};

// bool IsPrime(int num);
void insertAtBeginning(Node*& list, int value);
void showList(Node* list);
void deleteValue(Node*& list, int value); // Deletes first occurrence
void freeList(Node*& list);


#endif
