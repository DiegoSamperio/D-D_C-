#include "Node.h"
#include "Monster.h"
#include "Dugeon.h"
#include "Skill.h"
#include "Spell.h"

// Constructor: Initializes a node with the given value and sets next and previous pointers to null
template <typename T>
Node<T>::Node(T value) {
    this->data = value;
    this->next = nullptr;
    this->prev = nullptr;
}

// Returns the data stored in the node
template <typename T>
T Node<T>::getData() const {
    return data;
}

// Sets the data of the node
template <typename T>
void Node<T>::setData(T value) {
    data = value;
}

// Returns the pointer to the next node
template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

// Sets the pointer to the next node
template <typename T>
void Node<T>::setNext(Node* node) {
    next = node;
}

// Returns the pointer to the previous node
template <typename T>
Node<T>* Node<T>::getPrev() const {
    return prev;
}

// Sets the pointer to the previous node
template <typename T>
void Node<T>::setPrev(Node* node) {
    prev = node;
}

// Explicit template instantiation for specific types
template class Node<Monster>;
template class Node<Dugeon>;
template class Node<Skill>;
template class Node<Spell>;