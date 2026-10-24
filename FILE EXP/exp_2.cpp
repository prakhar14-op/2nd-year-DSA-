#include <iostream>
using namespace std;

int main() {

    int size; // 'size' will be the capacity of our stack
    cout << "Enter the size (capacity) of the stack: ";
    cin >> size;

    int stack[size];
    int top = -1; // 'top' tracks the index of the top-most element
                  // -1 means the stack is empty

    // --- PUSH Operation ---
    cout << "\n--- Stack Push ---" << endl;
    int num_to_push;
    cout << "How many elements do you want to push?: ";
    cin >> num_to_push;

    for (int i = 0; i < num_to_push; i++) {
        // Check for Stack Overflow
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push any more elements." << endl;
            break; // Stop the loop
        }

        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        top++; // Move the 'top' pointer up
        stack[top] = element; // Add the element at the new 'top'
        cout << element << " was pushed to the stack." << endl;
    }

    // --- DISPLAY Operation ---
    cout << "\n--- Display Stack ---" << endl;
    
    // Check if stack is empty
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Elements in stack (from top to bottom): ";
        // We loop from 'top' down to 0 to print in correct order
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    // --- POP Operation ---
    cout << "\n--- Stack Pop ---" << endl;
    int num_to_pop;
    cout << "How many elements do you want to pop?: ";
    cin >> num_to_pop;

    for (int i = 0; i < num_to_pop; i++) {
        // Check for Stack Underflow
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop any more elements." << endl;
            break; // Stop the loop
        }

        int popped_element = stack[top]; // Get the top element
        top--; // Move the 'top' pointer down
        cout << "Element " << popped_element << " was popped from the stack." << endl;
    }

    // --- FINAL DISPLAY ---
    cout << "\n--- Final Stack Display ---" << endl;
    
    // Check if stack is empty
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Final elements in stack (from top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    return 0;
}