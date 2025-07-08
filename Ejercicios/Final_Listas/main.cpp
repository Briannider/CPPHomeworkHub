#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main()
{
    Node *list = nullptr;

    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);

    printList(list);

    freeList(list);
    return 0;
}
