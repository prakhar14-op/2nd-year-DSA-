#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Pointer to the *next* node in the list
};
int main() {
    Node* tail = NULL;
    
    Node* temp = NULL;    // A temporary pointer
    Node* newNode = NULL; // For creating new nodes

    //  1. INSERTION AT THE END
    // (This is also our initial insertion)
    cout << " Insertion at End " << endl;
    int num_to_add;
    cout << "How many elements do you want to add?: ";
    cin >> num_to_add;

    for (int i = 0; i < num_to_add; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        //  Logic to insert at the end
        
        // 1. Create the new node
        newNode = new Node();
        newNode->data = element;

        // 2. Check if the list is empty
        if (tail == NULL) {
            tail = newNode;       // This is the only node
            tail->next = tail;  // So it points to itself
        }

         else {
 // 3. If not empty:
 newNode->next = tail->next; // New node points to the current head
 tail->next = newNode; // Old tail points to the new node
 tail = newNode; // The new node becomes the new tail
 }
 cout << element << " was inserted at the end." << endl;
 // 
 }
 //  2. DISPLAY Operation 
 cout << "\n Display List " << endl;
 if (tail == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (starting from head): ";
 
 temp = tail->next; // Start at the head
 
 // We use a do-while loop to make sure it runs at least once
 do {
 cout << temp->data << " -> "; // Print data
 temp = temp->next; // Move to the next node
 } while (temp != tail->next); // Loop until we are back at the head
 
 cout << "(back to head)" << endl;
 }
 
 //  3. INSERTION AT THE BEGINNING 
 cout << "\n Insertion at Beginning " << endl;
 int element;
 cout << "Enter an element to insert at the beginning: ";
 cin >> element;
 // 1. Create the new node
 newNode = new Node();
 newNode->data = element;
 if (tail == NULL) { // If list is empty
 tail = newNode;
 tail->next = tail;
 } else {
 // Logic to insert at the beginning 
 newNode->next = tail->next; // 1. New node points to the current head
 tail->next = newNode; // 2. The tail now points to the new node
 // (making it the new head)
 }
 cout << element << " was inserted at the beginning." << endl;
 // 
 // 4. DISPLAY Operation 
 cout << "\n Display List (After Beginning Insert) " << endl;
 if (tail == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (starting from head): ";
 temp = tail->next;
 do {
 cout << temp->data << " -> ";
 temp = temp->next;
 } while (temp != tail->next);
 cout << "(back to head)" << endl;
 }
 // 5. DELETION FROM THE BEGINNING 
 cout << "\n Deletion from Beginning " << endl;
 if (tail == NULL) {
 cout << "List is already empty." << endl;
 } else if (tail->next == tail) {
 // Only one node in the list
 int deleted_data = tail->data;
 delete tail;
 tail = NULL; // List is now empty
 cout << "Element " << deleted_data << " (the only node) was deleted." << endl;
 } else {
 // Logic to delete from the beginning (at least 2 nodes) 
 temp = tail->next; // 1. 'temp' points to the head (which we will delete)
 int deleted_data = temp->data;
 
 // 2. The tail's 'next' pointer must "skip over" the old head
 // and point to the *second* node.
 tail->next = temp->next;
 
 // 3. Delete the old head node
 delete temp;
 cout << "Element " << deleted_data << " was deleted from the beginning." << endl;
 // 
 }
 
 // 6. FINAL DISPLAY
 cout << "\n Final List Display " << endl;
 if (tail == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (starting from head): ";
 temp = tail->next;
 do {
 cout << temp->data << " -> ";
 temp = temp->next;
 } while (temp != tail->next);
 cout << "(back to head)" << endl;
 }
 return 0;
}