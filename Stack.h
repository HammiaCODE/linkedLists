//
// Created by hanes on 9/24/2024.
//
#include <iostream>;
using namespace std;

#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

class linkedList {
private:
    Node* topNode;

public:
    linkedList(): topNode(nullptr){}

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if(!topNode) {
            topNode = newNode;
            return;
        }

        Node* temp = topNode;
        while (temp->next) {
            temp = temp -> next;
        }

        temp -> next = newNode;
    }


    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        // Traverse to the node before the desired position
        Node* temp = topNode;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        // If the position is out of range, print an error message
        if (!temp) {
            cout << "Out of range" << endl;
            delete newNode;
            return;
        }

        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (!topNode) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Function to Delete the last node of the list
    void deleteFromEnd() {
        if (!topNode) {
            cout << "The list is empty" << endl;
            return;
        }

        if (!topNode->next) {
            delete topNode;
            topNode = nullptr;
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = topNode;
        while (temp->next->next) {
            temp = temp->next;
        }

        //  Delete the last node
        delete temp->next;
        // Set the second-to-last node's next to NULL
        temp->next = nullptr;
    }

    // Function to Delete a node at a specific position in the list
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = topNode;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        // Save the node to be deleted
        Node* nodeToDelete = temp->next;
        // Update the next pointer
        temp->next = temp->next->next;
        // Delete the node
        delete nodeToDelete;
    }

    void display() {
        if (!topNode) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = topNode;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


#endif //STACK_H
