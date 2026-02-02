#ifndef QUEUE_H
#define QUEUE_H 

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* frontPtr;
    Node* rearPtr;

public:
    Queue();
    ~Queue();

    void enqueue(int value);
    bool dequeue(int &dequeuedValue);
    bool front(int &frontValue) const;
    bool isEmpty() const;

};          

#endif