#include <iostream>
#include "Stack.h"

int main(){
    Stack s;        // creating an empty stack
    int value;      // this will hold my top value;

    std::cout << "Pushing 10 and 20 onto stack...\n";
    s.push(10);
    s.push(20);

    if (s.peek(value)){
        std::cout << "Top: " << value << '\n';
    }
    while(s.pop(value)){
        std::cout << "Popped: " << value << '\n';
    }
    if(!s.pop(value)){
        std::cout << "Stack is empty!\n";
    }
    
    return 0;
}