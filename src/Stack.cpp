#include "Stack.h"

Stack::Stack() : top(nullptr) {}  // Constructor initializes top to nullptr

Stack::~Stack() {       // Destructor to clean up the stack
    int temp;           // Temporary variable to hold popped values
    while (pop(temp));  // Pop all elements to free memory. Keep popping until pop() returns false
}

void Stack::push(int value){      // :: scope resolution operator to define member function outside class
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
bool Stack::pop(int &poppedValue){
    if(isEmpty()) return false;

    Node* temp = top;
    poppedValue = top->data;
    top = top->next;
    delete temp;
    return true;
}
bool Stack::peek(int &topValue) const{      // This function promises NOT to modify the object’s state.
    if (isEmpty()) return false;

    topValue = top->data;
    return true;
}
bool Stack::isEmpty() const{
    return top == nullptr;
}

