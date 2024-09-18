
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class SortedLinkedList {
public:
    Node* head;

    SortedLinkedList() : head(nullptr) {}

    // Insertar un valor en la lista ordenada
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head || head->value > value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->value < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Buscar un valor en la lista
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Borrar lista
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

#endif //SORTEDLINKEDLIST_H
