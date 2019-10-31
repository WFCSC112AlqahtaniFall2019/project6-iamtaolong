//
// Created by Tao on 10/30/19.
//

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"
#include <iostream>

class LinkedList {

    public:

        // write a LinkedList class as a friend of the Node class
        friend class Node;

        // default constructor
        LinkedList();

        // copy constructor
        LinkedList(const LinkedList &list);

        // copy operator
        LinkedList& operator= (const LinkedList &list);

        // destructor
        ~ LinkedList();

        // sort
        void LinkedinsertionSort();

        // add new node to our list
        void add(int newNode);

        // print out linked list to the screen
        void print();


    private:

        // get head
        Node* head;

};





#endif //BINARYINSERTIONSORT_LINKEDLIST_H
