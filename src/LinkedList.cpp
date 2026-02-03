#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    head == nullptr;        // constructor makes empty with null headptr
}

LinkedList::~LinkedList(){  // destructor that iterates through list and deletes all nodes
    Node* current = head;
    while(current != nullptr){
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::insertAtBeginning(int value){  // insert at beginning
    Node* temp = new Node{value, head};  // Create new node
    head = temp;
}

void LinkedList::insertAtEnd(int value){    // insert at end
    Node* temp = new Node{value, nullptr};

    if(head == nullptr){        // List is empty
        head = temp;
        return;
    }

    Node* current = head;
    while(current->next != nullptr){    // Traverse to the end of the list
        current = current->next;
    }
    current->next = temp;   // Insert at the end
}

bool LinkedList::deleteValue(int value){    // delete a value and return a bool
    if(head == nullptr) return false;   // if list is empty

    if(head->data == value){    // if value is at head
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;      // value to traverse the linkedList
    while(current->next != nullptr && current->next->data != value){
        current = current->next;
    }

    if(current->next == nullptr) return false;  // value is not found

    Node* temp = current->next;     // store valueToDelete in temp to reassign nodes and delete it
    current->next = temp->next;
    delete temp;
    return true;
}

void LinkedList::display() const{   // iterate through list and display elements
    Node* current = head;
    while(current != nullptr){
        std::cout << "[" << current->data << "]" << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}