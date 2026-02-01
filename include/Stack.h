// Header file for my stack Data structure

#ifndef STACK_H        
#define STACK_H         

class Stack {           // Stack class definition
private:
    struct Node{
        int data;
        Node* next;
    };

    Node* top;      // Pointer to the top of the stack

public:
    Stack();        // Constructor
    ~Stack();       // Destructor
    
    // Member functions
    void push(int value);       // Push value onto the stack
    bool pop(int &poppedValue);     // Pop value from the stack
    bool peek(int &topValue) const;       // Peek at the top value of the stack 
    bool isEmpty() const;       // Check if the stack is empty
};


#endif
