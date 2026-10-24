#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free all allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Add an element to the top
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed " << data << " to the stack." << std::endl;
    }

    // Remove the top element and return its value
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow: Cannot pop from an empty stack." << std::endl;
            return -1; // Or throw an exception
        }
        Node* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp; // Free the old top node
        return poppedData;
    }

    // Get the top element without removing it
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // Or throw an exception
        }
        return top->data;
    }

    // Display the stack contents
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack (top to bottom):" << std::endl;
        Node* current = top;
        while (current != nullptr) {
            std::cout << "  " << current->data << std::endl;
            current = current->next;
        }
    }
};

// --- Demo Usage ---
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    std::cout << "\nTop element is: " << s.peek() << std::endl;

    std::cout << "\nPopped element: " << s.pop() << std::endl;

    s.display();

    std::cout << "\nPopped element: " << s.pop() << std::endl;
    std::cout << "Popped element: " << s.pop() << std::endl;
    s.pop(); // This will trigger underflow

    return 0;
}