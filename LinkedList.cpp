#include "LinkedList.h"
#include "Monster.h"
#include "Dugeon.h"
#include "Spell.h"
#include "Skill.h"
#include <iostream>
using namespace std;

// Constructor: Initializes an empty linked list
template <typename T>
LinkedList<T>::LinkedList() {
    first = nullptr;
    tail = nullptr;
}

// Prints all nodes in the linked list
template <typename T>
void LinkedList<T>::print() {
    Node<T> *temp = first;
    while (temp != nullptr) {
        cout << temp->getData() << endl; // Print the data in each node
        temp = temp->getNext(); // Move to the next node
    }
}

// Adds a new node with the given data to the end of the list
template <typename T>
void LinkedList<T>::addNode(T data) {
    Node<T>* node = new Node<T>(data);
    if (!first) {
        // If the list is empty, set the first and tail to the new node
        first = node;
        tail = node;
    } else {
        // Otherwise, add the node to the end of the list
        Node<T> *current = tail;
        current->setNext(node);
        node->setPrev(current);
        tail = node; // Update the tail
    }
}

// Finds the node at the given position (0-based index)
template <typename T>
Node<T>* LinkedList<T>::findAtPos(int pos) {
    Node<T> *temp = first;
    int count = 0;
    while (temp != nullptr) {
        if (count == pos) {
            return temp; // Return the node at the specified position
        }
        count++;
        temp = temp->getNext();
    }
    return nullptr; // Return nullptr if the position is out of bounds
}

// Returns the size of the linked list
template <typename T>
int LinkedList<T>::size() {
    if (first == nullptr) return 0; // If the list is empty, return 0
    Node<T> *iter = first;
    int count = 0;
    while (iter != nullptr) {
        count++; // Count each node
        iter = iter->getNext();
    }
    return count;
}

// Finds the node with the given data
template <typename T>
Node<T>* LinkedList<T>::findNode(T data) {
    Node<T>* temp = first;
    while (temp != nullptr) {
        if (temp->getData() == data) {
            return temp; // Return the node if data matches
        }
        temp = temp->getNext(); // Move to the next node
    }
    return nullptr; // Return nullptr if the data is not found
}

// Removes a node from the list
template <typename T>
void LinkedList<T>::removeNodeAt(Node<T>* node) {
    if (!node) {
        return; // If the node is null, do nothing
    }

    // If the node is the first node
    if (node == first) {
        first = node->getNext(); // Update the first node
    }

    // If the node is the last node
    if (node == tail) {
        tail = node->getPrev(); // Update the tail node
    }

    // Update the pointers of the previous and next nodes
    if (node->getPrev()) {
        node->getPrev()->setNext(node->getNext());
    }

    if (node->getNext()) {
        node->getNext()->setPrev(node->getPrev());
    }

    // Free the memory of the node
    delete node;
}

// Returns the first node in the list
template<typename T>
Node<T>* LinkedList<T>::getFirst() const {
    return first;
}

// Sets the first node in the list
template<typename T>
void LinkedList<T>::setFirst(Node<T>* first) {
    LinkedList::first = first;
}

// Returns the last node in the list
template<typename T>
Node<T>* LinkedList<T>::getTail() const {
    return tail;
}

// Sets the last node in the list
template<typename T>
void LinkedList<T>::setTail(Node<T>* tail) {
    LinkedList::tail = tail;
}

// Explicit template instantiation for specific types
template class LinkedList<Monster>;
template class LinkedList<Dugeon>;
template class LinkedList<Spell>;
template class LinkedList<Skill>;
