#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next; // Pointer to the *next* node in the list
};

int main() {

    // 'head' is a pointer to the very first Node in our list.
    // We start it at NULL to show the list is empty.
    Node* head = NULL;
    Node* temp = NULL; // A temporary pointer for various tasks
    Node* newNode = NULL; // A pointer for creating new nodes

    //  1. INSERTION AT THE END 
    cout << "Insertion at End" << endl;
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
        newNode->next = NULL; // It's the last, so it points to nothing
         // 2. Check if the list is empty
 if (head == NULL) {
 head = newNode; // The new node is now the head
 } else {
 // 3. If not empty, find the *current* last node
 temp = head;
 while (temp->next != NULL) {
 temp = temp->next; // Keep walking until we stop at the last node
 }
 
 // 4. Link the old last node to our new node
 temp->next = newNode;
 }
 cout << element << " was inserted at the end." << endl;
 // 
 }
 //  2. DISPLAY Operation 
 cout << "\n Display List " << endl;
 if (head == NULL) {
 cout << "List is empty." << endl;
 } else {
 cout << "List elements (head to tail): ";
 temp = head; // Start at the beginning
 while (temp != NULL) {
 cout << temp->data << " -> "; // Print data
 temp = temp->next; // Move to the next node
 }
 cout << "NULL" << endl;
 }
 // 
 //  3. INSERTION AT THE BEGINNING 
 cout << "\n Insertion at Beginning " << endl;
 int element;
 cout << "Enter an element to insert at the beginning: ";
 cin >> element;
 //  Logic to insert at the beginning 
 newNode = new Node();
 newNode->data = element;
 newNode->next = head; // 1. Point the new node to the *current* head
 head = newNode; // 2. Move the 'head' pointer to the new node
 cout << element << " was inserted at the beginning." << endl;
 // 
 //  4. DISPLAY Operation 
 cout << "\n Display List (After Beginning Insert) " << endl;
 temp = head;
 while (temp != NULL) {
 cout << temp->data << " -> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
 //  5. DELETION FROM THE BEGINNING 
 cout << "\n Deletion from Beginning " << endl;
 if (head == NULL) {
 cout << "List is already empty." << endl;
 } else {
 //  Logic to delete from the beginning 
 int deleted_data = head->data;
 temp = head; // 1. Save a temp pointer to the node we will delete
 head = head->next; // 2. Move the 'head' pointer to the 2nd node
 delete temp; // 3. Delete the old head node
 cout << "Element " << deleted_data << " was deleted from the beginning." << endl;
 // 
 }
 
 //  6. DELETION FROM THE END 
 cout << "\n Deletion from End " << endl;
 if (head == NULL) {
 cout << "List is empty." << endl;
 } else if (head->next == NULL) {
 // Only one node in the list
 int deleted_data = head->data;
 delete head;
 head = NULL; // List is now empty
 cout << "Element " << deleted_data << " (the last node) was deleted." << endl;
 } else {
 //  Logic to delete from the end (at least 2 nodes) 
 // We must find the *second to last* node
 Node* second_last = head;
 while (second_last->next->next != NULL) {
 second_last = second_last->next;
 }
 
 // Now 'second_last->next' is the node to delete
 int deleted_data = second_last->next->data;
 delete second_last->next; // Delete the last node
 second_last->next = NULL; // Set the new last node's pointer to NULL
 cout << "Element " << deleted_data << " was deleted from the end." << endl;
 // 
 }
 //  7. FINAL DISPLAY 
 cout << "\n Final List Display " << endl;
 if (head == NULL) {
 cout << "List is empty." << endl;
 } else {
 temp = head;
 while (temp != NULL) {
 cout << temp->data << " -> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
 }
 return 0;
}