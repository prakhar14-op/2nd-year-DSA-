#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; // Pointer to the *next* node
    Node* prev; // Pointer to the *previous* node
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    Node* temp = NULL;    // A temporary pointer
    Node* newNode = NULL; // For creating new nodes

    //  1. INSERTION AT THE END 
    cout << " Insertion at End" << endl;
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
        newNode->next = NULL; // It's the new tail, so its 'next' is NULL
        
        // 2. Check if the list is empty
 if (head == NULL) {
 // If empty, it's the only node
 newNode->prev = NULL;
 head = newNode;
 tail = newNode;
 } else {
 // 3. If not empty, link it to the old tail
 newNode->prev = tail; // New node's 'prev' points to the old tail
 tail->next = newNode; // Old tail's 'next' points to the new node
 
 // 4. Update the 'tail' pointer
 tail = newNode;
 }
 cout << element << " was inserted at the end." << endl;
 // [Image of Doubly Linked List insertion at end]
 }
 // [Image of a Doubly Linked List data structure]
 //  2. DISPLAY (FORWARD) 
 cout << "\n Display List (Forward) " << endl;
 if (head == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (head to tail): NULL <-> ";
 temp = head; // Start at the beginning
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->next; // Move to the next node
 }
 cout << "NULL" << endl;
 }
 //  3. DISPLAY (BACKWARD) 
 // This is the cool part of a Doubly Linked List!
 cout << "\n Display List (Backward) " << endl;
 if (tail == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (tail to head): NULL <-> ";
 temp = tail; // Start at the end
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->prev; // Move to the previous node
 }
 cout << "NULL" << endl;
 }
 //  4. DELETION FROM THE END 
 cout << "\n Deletion from End " << endl;
 if (head == NULL) { // or tail == NULL
 cout << "List is already empty." << endl;
 } else if (head == tail) {
 // Only one node in the list
 int deleted_data = head->data;
 delete head;
 head = NULL; // List is now empty
 tail = NULL;
 cout << "Element " << deleted_data << " (the last node) was deleted." << endl;
 } else {
 //  Logic to delete from the end (fast!) 
 int deleted_data = tail->data;
 temp = tail; // 1. Save temp pointer to the node we will delete
 
 // 2. Move 'tail' pointer back to the *second to last* node
 tail = tail->prev; 
 
 // 3. Set the new tail's 'next' pointer to NULL
 tail->next = NULL;
 // 4. Delete the old tail node
 delete temp;
 cout << "Element " << deleted_data << " was deleted from the end." << endl;
 // [Image of Doubly Linked List deletion from end]
 }
 //  5. FINAL DISPLAY (FORWARD) 
 cout << "\n Final List Display (Forward) " << endl;
 if (head == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List (head to tail): NULL <-> ";
 temp = head;
 while (temp != NULL) {
 cout << temp->data << " <-> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
 }
 return 0;
}