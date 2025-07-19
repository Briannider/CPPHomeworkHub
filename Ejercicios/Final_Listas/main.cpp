#include "LinkedList.hpp"
#include <iostream>
using namespace std;

int main()
{   
    /*   // Uncomment the following lines to test the IsPrime function
    int num;
    cout<<"Input a number: "<<endl;
    cin>>num;
    if(IsPrime(num)){
        cout<<"Is prime"<<endl;
    }else{
        cout<<"Is not prime"<<endl;
    }
    */
    /*
    int even = 0;
    int maxeven = 0;
    // Generate a vector of 50 random numbers between 1 and 100
    int vector[50];
    for (int i = 0; i < 50; ++i) {
        vector[i] = rand() % 100 + 1; // random numbers between 1 and 100
    }

    for (int i = 0; i<50; i += 10) {
        even = 0; // Reset even count for each new set of 10 numbers
        cout << "Set of 10 numbers: " << endl;
        for (int j = 0; j < 10; j++){
            cout << vector[i + j]<<endl;
            // Check if the number is even
            if(vector[i + j] % 2 == 0) {
                even++;
                if(vector[i + j] > maxeven) {
                    maxeven = vector[i + j];
                }
            }
        }
        cout << "Count of even numbers: "<< even <<endl;
    }
    cout << "Maximum even number: "<< maxeven <<endl;


    */

    Node* list = nullptr; // Initialize the linked list
    int value;
    cout<<"Input 5 numbers: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertAtBeginning(list, value);
        cout << "Inserted: " << list->value << endl;
    }
    showList(list);
    freeList(list); // Free the linked list memory
    cout << "List freed." << endl;
    

    return 0;
}
