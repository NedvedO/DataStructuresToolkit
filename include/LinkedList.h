#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
private:
    struct Node{
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    bool deleteValue(int value);
    void display() const;

};

#endif