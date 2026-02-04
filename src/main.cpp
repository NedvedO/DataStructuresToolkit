#include <iostream>
#include <limits>

#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

// ---Helper Function for Valid Input---

/* I wrote a helper function that repeatedly prompts the user until 
    std::cin successfully extracts an integer. If extraction fails, I clear 
    the error state and flush the input buffer using std::numeric_limits<std::streamsize>::max().”
*/

// takes a message to display & returns a valid integer
/* “Because string literals in C++ are stored as null-terminated character 
    arrays and decay to const char* when passed to functions. Marking it 
    const ensures the string isn’t modified.”*/
static int readInt(const char* prompt) { // This function has internal linkage — it’s only visible inside this .cpp file.
    int x;
    while(true) {       // infinite loop that only exits when valid input is received
        std::cout << prompt;    // prompt the user
        if(std::cin >> x) return x; // if input is valid, function returnsn x

        // Error message for invalid input
        std::cout << "Invalid input. Please enter an integer. \n";
        std::cin.clear();   // clear the error state so cin can be used again
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flushes the bad input fron the buffer, without this the loop would run forever
    }
}

static void stackMenu(Stack &s) {
    while(true) {
        std::cout << "\n=== Stack Menu===\n"
                << "1. Push\n"
                << "2. Pop\n"
                << "3. Peek\n"
                << "4. Is Empty\n"
                << "0. Back\n";

    int choice = readInt("Choose: ");
    if (choice == 0) return;

    int value;
    switch (choice) {
        case 1:
            value = readInt("Value to push: ");
            s.push(value);
            std::cout << "Pushed: " << value << "\n";
            break;
        case 2:
            if(s.pop(value)) std::cout << "Popped: " << value << "\n";
            else std::cout << "Stack is Empty. \n";
            break;
        case 3:
            if(s.peek(value)) std::cout << "Top: " << value << "\n";
            else std::cout << "Stack is Empty. \n";
            break;
        case 4:
            std::cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n"); // in parentheses for precedence
            break;
        default:
            std::cout << "Invalid option.\n";
        }
    }
}

static void queueMenu(Queue &q){
    while(true){
        std::cout << "\n=== Queue Menu===\n"
                    << "1. Enqueue\n"
                    << "2. Dequeue\n"
                    << "3. Front\n"
                    << "4. Is Empty\n"
                    << "0. Back\n";
        
        int choice = readInt("Choose: ");
        if(choice == 0) return;

        int value;
        switch(choice){
            case 1:
                value = readInt("Value to enqueue: ");
                q.enqueue(value);
                std::cout << "Enqueued.\n";
                break;
            case 2:
                if(q.dequeue(value)) std::cout << "Dequeued: " << value << "\n";
                else std::cout << "List is empty.\n";
                break;
            case 3:
                if(q.front(value)) std::cout << "Front: " << value << '\n';
                else std::cout << "List is empty.\n";
                break;
            case 4:
                std::cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty.\n");
                break;
            default:
                std::cout << "Invalid input. Try again.\n";
        }
    }        
}

static void linkedListMenu(LinkedList &l){
    while(true){
        std::cout << "\n=== Linked List Menu===\n"
                << "1. Insert at Beginning\n"
                << "2. Insert at End\n"
                << "3. Delete Value\n"
                << "4. Display List\n"
                << "0. Back\n";

        int choice = readInt("Choose: ");
        if(choice == 0) return;
        
        int value;
        switch(choice) {
            case 1:
                value = readInt("Value to insert at beginning: ");
                l.insertAtBeginning(value);
                std::cout << "Inserted.\n";
                break;
            case 2:
                value = readInt("Value to insert at end: ");
                l.insertAtEnd(value);
                std::cout << "Inserted.\n";
                break;        
            case 3:
                value = readInt("Value to delete: ");
                if(l.deleteValue(value)){
                    std::cout << "Deleted.\n";
                }
                else std::cout << "Value not found.\n";
                break;
            case 4:
                l.display();
                break;
            default:
                std::cout << "Invalid input.";
        }
    }
}

int main(){
    Stack s;
    Queue q;
    LinkedList l;

    while(true){
        std::cout << "\n=== Data Structures Toolkit\n"
                    << "1. Stack\n"
                    << "2. Queue\n"
                    << "3. Linked List\n"
                    << "0. Exit\n";
        
        int choice = readInt("Choose: ");
        if(choice == 0) break;

        switch(choice){
            case 1: stackMenu(s); break;
            case 2: queueMenu(q); break;
            case 3: linkedListMenu(l); break;
            default: std::cout << "Invalid option.\n";
        }
    }
    std::cout << "Thank you. Goodbye.\n";
    return 0;
}