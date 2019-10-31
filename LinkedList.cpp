//
// Created by Tao on 10/30/19.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

// Implement the “big three”: copy constructor, copy assignment operator, and destructor for the LinkedList class

// big 3: default constructor
LinkedList :: LinkedList() {

    // initialize it by seeting a nullptr to the head
    head = nullptr;
}

// big 3: copy constructor
LinkedList :: LinkedList(const LinkedList &list) {

    // node new objects and have a head
    Node* current = list.head;
    Node* currentNew = head;

    // copying from the first
    while (current -> next != nullptr){
        currentNew -> next = new Node(current -> next -> value);
        currentNew = currentNew -> next;
        current = current -> next;
    }
}

// big 3: copy constructor / operator
LinkedList& LinkedList::operator=(const LinkedList &assign) {

    // initialize a new object named copy
    // use the swap and copy idiom
    LinkedList temp;
    swap(temp.head, head);
    return *this;
}

// big 3: deconstructor
LinkedList :: ~LinkedList() {

    // get current and next which is the first and second node
    Node* current = head;
    Node* next = current -> next;

    // using a while loop for deletion
    // run and delete until the current reach the nullptr
    while( current -> next != nullptr){
        delete(current);
        current = next;
        next = next -> next;
    }

}

// using append elements to copy the elements from the vector to the linkedlist
// have two cases and 1 is empty; 2 is not empty
void LinkedList :: add(int newNode) {

    // case 1: empty
    if (head == nullptr){
        head = new Node(newNode);
    }

    // case 2
    else {
        Node* add = head;
        while (add -> next != nullptr){
            add = add -> next;
        }
        add -> next = new Node (newNode);
    }
}

// print the list out
// have two cases and 1 is empty; 2 is not empty
void LinkedList::print() {

    // get head
    Node* add = head;

    // case 1: empty
    if (!add) {
        cout << "Empty list." << endl;
    }
        //else it prints a node until there is no nodes left
    else{
        while(add){
            cout << add -> value << " ";
            add = add -> next;
        }
    }
    cout << endl;
}


// sorting

void LinkedList::LinkedinsertionSort() {

    // case1: empty list
    if ( head == nullptr ){
        return;
    }

    // case2: only 1 element, no need for sorting
    if ( head -> next == nullptr){
        return;
    }

    // now the list is okay to do sorting
    // initialize three nodes
    Node* temp;
    Node* before = head;
    Node* next = head -> next;

    // use a big while put to run until reaching the null()
    while (next != nullptr){

        // compare the value between the before and next
        // case, if the next one is smaller than the one before, next < before
        if (next -> value < before -> value) {

            // if we find the next's value is smaller than the first value in the list
            if(next -> value < head -> value){

                // we remove the link with the previous node
                // replace its place of the first node
                before -> next = next -> next;

                // set nullptr
                next -> next = nullptr;
                next -> next = head;

                // assign head to the currently smallest value
                head = next;
            }

            // smaller but not the smallest, just swap
            else{

                // get the temp and copying the head to it
                temp = head;

                // find where to make insertion
                while ((next -> value) > (temp -> next -> value) && (temp -> next) != nullptr){

                    // change
                    temp = temp -> next;
                }

                // we cancel the link
                before->next = next->next;
                next->next = nullptr;

                // create new link
                next->next = temp->next;
                temp->next = next;
            }
        }

            // compare the value between the before and next
            // another if the next one is bigger, next>=before
        else{

            // no change in values and positions
            // proceed to the next node
            before = before -> next;
            next = next -> next;
        }

        // proceed to the next node
        next = before -> next;
    }
}

