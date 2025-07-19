#include "LinkedList.hpp"
#include <iostream>
using namespace std;

// Function to check if a number is prime
// Returns true if the number is prime, false otherwise
/*
bool IsPrime(int num){
    if(num<=1)return false; //! 1 and 0 are not prime

    for(int i = 2; i<=num/2; i++){
        if (num % i == 0) return false; //! it has a divisor → it is not prime
    }

    return true; //! There isn't any prime number
}
*/

void insertAtBeginning(Node*& list, int value){
Node *newnode = new Node; // Create a new node
newnode -> value = value; //  Set the value
newnode -> next = list; // Point new node to the current head
list = newnode; // Update head to new node
};
void showList(Node* list){
    Node* current = list; // Start from the head
    while(current != nullptr){
        cout << current -> value << " ";
        current = current -> next;
    }
    cout<< endl; // New line after printing all values
};
void deleteValue(Node*& list, int value){
    Node* current = list;
    Node* previous = nullptr;
    while(current != nullptr && current -> value != value){
        previous = current; // Keep track of the previous node
        current = current -> next; // Move to the next node
    }
    if(current != nullptr){ // If we found the value
        if(previous != nullptr){ // If it's not the first node
            previous -> next = current -> next;
        }else{ // If it is the first node
            list = current -> next;
        }
        delete current; // Free the memory
    }
    else{
        cout << "Value not found in the list." << endl; // Value not found
    }
}; // Deletes first occurrence
void freeList(Node*& list){
    Node* current = nullptr;
    while(list != nullptr){ // While there are nodes in the list
        current = list; // Save the current node
        list = list -> next; // Move to the next node
        delete current; // Free the memory of the current node
    }
};
