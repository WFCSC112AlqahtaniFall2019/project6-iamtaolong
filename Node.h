#ifndef NODE_H
#define NODE_H

class Node {
public:

    // Node constructor
    Node(int v = 0, Node* n = nullptr)
    {
        value = v;
        next = n;
    }

    // write a LinkedList class as a friend of the Node class
    friend class LinkedList;

private:

    // get value
    int value;
    Node* next;

};

#endif //NODE_H
