#ifndef PROYECTOESTRUCTURADATOS_LINKEDLIST_H
#define PROYECTOESTRUCTURADATOS_LINKEDLIST_H

#include "Node.h"

// Generic LinkedList class template
template <typename T>
class LinkedList {
private:
    Node<T> *first; // Pointer to the first node
    Node<T> *tail;  // Pointer to the last node

public:
    LinkedList(); // Constructor

    Node<T>* getFirst() const; // Returns the first node
    void setFirst(Node<T> *first); // Sets the first node

    Node<T>* getTail() const; // Returns the last node
    void setTail(Node<T> *tail); // Sets the last node

    void print(); // Prints the list
    Node<T>* findAtPos(int pos); // Finds a node at a given position
    void addNode(T data); // Adds a new node with the given data to the list

    int size(); // Returns the size of the list
    Node<T>* findNode(T data); // Finds a node with the given data
    void removeNodeAt(Node<T>* node); // Removes a node from the list at the given node
};

#endif
