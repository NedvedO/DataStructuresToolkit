#include "Queue.h"

Queue::Queue() : frontPtr(nullptr), rearPtr(nullptr) {};

Queue::~Queue(){
    int temp;
    while(dequeue(temp));
}

void Queue::enqueue(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(isEmpty()){
        frontPtr = newNode;
        rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
}

bool Queue::dequeue(int &dequeuedValue){
    if(isEmpty()) return false;

    Node* temp = frontPtr;
    dequeuedValue = frontPtr->data;
    frontPtr = frontPtr->next;

    if(frontPtr == nullptr){
        rearPtr = nullptr;
    }
    delete temp;
    return true;
}

bool Queue::front(int &frontValue) const{
    if(isEmpty()) return false;

    frontValue = frontPtr->data;
    return true;
}

bool Queue::isEmpty() const{
    return frontPtr == nullptr;
}