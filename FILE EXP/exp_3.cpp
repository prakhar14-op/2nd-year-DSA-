#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

int main() {
    Node* top = NULL;
    // PUSH Operation
    cout << " Stack Push " << endl;
    int num_to_push;
    cout << "How many elements do you want to push?: ";
    cin >> num_to_push;

    for (int i = 0; i < num_to_push; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        // This is the PUSH logic for a linked list:
        
        // 1. Create a brand new node
        Node* newNode = new Node();
        
        // 2. Set its data
        newNode->data = element;
        
        // 3. Point its 'next' to the *current* top node
        newNode->next = top;
        
        // 4. Make the 'top' pointer point to our new node
        top = newNode;
        
        cout << element << " was pushed to the stack." << endl;
    }

    // DISPLAY Operation
    cout << "\n Display Stack " << endl;
    
    // Check if stack is empty
    if (top == NULL) {
    cout << "Stack is empty." << endl;
    } else {
    cout << "Elements in stack (from top to bottom): ";
    
    // We need a temporary pointer to "walk" down the list
    Node* temp = top;
    
    // Loop as long as we haven't reached the end (NULL)
    while (temp != NULL) {
    cout << temp->data << " "; // Print the data
    temp = temp->next; // Move to the next node
    }
    cout << endl;
    }
    // POP Operation 
    cout << "\n Stack Pop " << endl;
    int num_to_pop;
    cout << "How many elements do you want to pop?: ";
    cin >> num_to_pop;
    for (int i = 0; i < num_to_pop; i++) {
    // Check for Stack Underflow
    if (top == NULL) {
    cout << "Stack Underflow! Cannot pop any more elements." << endl;
    break; // Stop the loop
    }
    // This is the POP logic for a linked list:
    // 1. Save the element we are about to pop (for display)
    int popped_element = top->data;
    
    // 2. Save a temporary pointer to the top node (so we can delete it)
    Node* temp = top;
    
    // 3. Move the 'top' pointer down to the *next* node in the list
    top = top->next;
    
    // 4. Delete the old top node to prevent memory leaks
    delete temp;
    
    cout << "Element " << popped_element << " was popped from the stack." << endl;
    }
    cout << "\n Final Stack Display " << endl;
    
    if (top == NULL) {
    cout << "Stack is empty." << endl;
    } else {
    cout << "Final elements in stack (from top to bottom): ";
    Node* temp = top;
    while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
    }
    cout << endl;
    }
    return 0;
}
 