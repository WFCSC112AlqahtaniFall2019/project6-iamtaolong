#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include <ctime>
#include "Node.h"
using namespace std;

int main() {

    // ask for seed from the user to make random numbers
    cout << "Enter a seed: ";
    int seed;
    cin >> seed;

    // ask for the length of the vector
    cout << "Enter the length: ";
    int length;
    cin >> length;

    // call ctime and srand
    srand(seed);
    cout << endl;

    // initialize a new vector
    vector<int> v(length);

    // use randomization to get numbers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    // print the unsorted list/vector
    cout << "Unsorted:           ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // FINISH ME
    LinkedList List = LinkedList();

    // copying the elements from the vector to the linkedList
    for (int i = 0; i < length; i++) {
        List.add(v[i]);
    }

    // binary insertion sort
    // get the total elapsed time by using end minus starts
    // use clock_t start to count time
    clock_t start_vector = clock();
    insertionSort(v, v.size());
    clock_t end_vector = clock();

    // get the total elapsed time by using end minus starts
    double elapsed_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }

    // using a for loop print out sorted list
    cout << "Sorted Vector:      ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " ;
    }
    cout << endl;

    // binary insertion sort
    // get the total elapsed time by using end minus starts
    // use clock_t start to count time
    clock_t start_linkedList = clock();
    List.LinkedinsertionSort();
    clock_t end_linkedList = clock();

    // get the total elapsed time by using end minus starts
    double elapsed_linkedList = double(end_linkedList - start_linkedList) / CLOCKS_PER_SEC;

    // calling the print() and print the sorted Linkedlist on the screen
    cout << "Sorted LinkedList:  " ;
    List.print();

    // cout the final elasped time
    cout << endl;
    cout << "Elapsed time for sorting a " << length << "-element vector or linkedlist: " << endl;
    cout << "                                Vector(BinaryInsertionSort): " << elapsed_vector << endl;
    cout << "                                  Linkedlist(InsertionSort): " << elapsed_linkedList << endl;

}

