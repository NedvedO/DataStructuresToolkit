#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main(){
    // --- Stack Test ---
    std::cout << "=== Stack Test ===\n";
    Stack s;        // creating an empty stack
    int value;      // this will hold my top value;

    std::cout << "Pushing 10 and 20 onto stack...\n";
    s.push(10);     // push 10 onto stack
    s.push(20);     // push 20 onto stack

    if (s.peek(value)){         // peek at the top value
        std::cout << "Top: " << value << '\n';
    }
    while(s.pop(value)){        // pop all values from stack
        std::cout << "Popped: " << value << '\n';
    }
    if(!s.pop(value)){          // try to pop from empty stack
        std::cout << "Stack is empty!\n\n";  
    }
    
    // --- Queue Test ---
    std::cout << "=== Queue Test ===\n";
    Queue q;

    std::cout << "Enqueue 5, 15, 25\n";
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    if (q.front(value)) std::cout << "Front value: " << value << "\n";

    while (q.dequeue(value)) {
        std::cout << "Dequeued: " << value << "\n";
    }
    if (!q.dequeue(value)) std::cout << "Queue is empty.\n";   


    return 0;
}