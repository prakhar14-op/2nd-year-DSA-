#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

int main() {
    Node* front = NULL; // 'front' points to the first person in line
    Node* rear = NULL;  // 'rear' points to the last person in line

    // ENQUEUE Operation (Add to Rear)
    cout << " Queue Enqueue" << endl;
    int num_to_enqueue;
    cout << "How many elements do you want to enqueue?: ";
    cin >> num_to_enqueue;

    for (int i = 0; i < num_to_enqueue; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        // This is the ENQUEUE logic 
        
        // 1. Create a brand new node
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = NULL; // The new node is last, so it points to nothing

        // 2. Check if the queue is empty
        if (front == NULL) {
            // If it's empty, this new node is BOTH the front and the rear
            front = newNode;
            rear = newNode;
        } 
        else {
        // 3. If it's not empty, link the *current* rear to this new node
        rear->next = newNode;
        
        // 4. Move the 'rear' pointer to be this new node
        rear = newNode;
        }
        // 
        cout << element << " was enqueued." << endl;
        }
        // DISPLAY Operation 
        cout << "\n Display Queue " << endl;
        
        // Check if queue is empty
        if (front == NULL) {
        cout << "Queue is empty." << endl;
        } else {
        cout << "Elements in queue (front to rear): ";
        
        // We need a temporary pointer to "walk" down the list
        Node* temp = front;
        
        // Loop as long as we haven't reached the end (NULL)
        while (temp != NULL) {
        cout << temp->data << " "; // Print the data
        temp = temp->next; // Move to the next node
        }
        cout << endl;
        }
        //  DEQUEUE Operation (Remove from Front) 
        cout << "\n Queue Dequeue " << endl;
        int num_to_dequeue;
        cout << "How many elements do you want to dequeue?: ";
        cin >> num_to_dequeue;
        for (int i = 0; i < num_to_dequeue; i++) {
        // Check for Queue Underflow
        if (front == NULL) {
        cout << "Queue Underflow! Cannot dequeue any more elements." << endl;
        break; // Stop the loop
        }
        //  This is the DEQUEUE logic 
        // 1. Save the element we are about to pop (for display)
        int dequeued_element = front->data;


         Node* temp = front;
 front = front->next;
 delete temp;
 
 if (front == NULL) {
 rear = NULL;
 }
 // 
 cout << "Element " << dequeued_element << " was dequeued." << endl;
 }
 // FINAL DISPLAY 
 cout << "\n Final Queue Display " << endl;
 
 if (front == NULL) {
 cout << "Queue is empty." << endl;
 } else {
 cout << "Final elements in queue (from top to bottom): ";
 Node* temp = front;
 while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
 return 0;
}