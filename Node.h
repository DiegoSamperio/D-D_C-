#ifndef PROYECTOESTRUCTURADATOS_NODE_H
#define PROYECTOESTRUCTURADATOS_NODE_H

// Template class Node for doubly linked list
template <typename T>
class Node {
private:
    T data; // Data stored in the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node

public:
    Node(T value); // Constructor to initialize a node with data

    T getData() const; // Returns the data stored in the node
    void setData(T value); // Sets the data of the node
    Node* getNext() const; // Returns the pointer to the next node
    void setNext(Node* node); // Sets the pointer to the next node
    Node* getPrev() const; // Returns the pointer to the previous node
    void setPrev(Node* node); // Sets the pointer to the previous node
};

#endif
