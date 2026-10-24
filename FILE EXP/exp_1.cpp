#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    // Input array elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    // Display array elements
    cout << "Array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    // Insertion operation
    int element, in_index;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter position to insert at (0 to " << size << "): ";
    cin >> in_index;
    if (in_index < 0 || in_index > size) {
        cout << "Enter valid index!" << endl;
    } else {
        // Shift elements to the right
        for (int i = size; i > in_index; i--) arr[i] = arr[i - 1];
        arr[in_index] = element;
        size++;
        cout << "Element inserted successfully." << endl;
    }
    // Display array after insertion
    cout << "Array after insertion: ";
    for (int i = 0; i < size; i++)cout << arr[i] << " ";
    cout << endl;
    // Deletion operation
    int del_index;
    cout << "Enter position to delete element from (0 to " << size - 1 << "): ";
    cin >> del_index;
    if (del_index < 0 || del_index >= size) {
        cout << "Enter valid index!" << endl;
    } else {
        // Shift elements to the left
        for (int i = del_index; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
        cout << "Element deleted successfully." << endl;
    }
    // Display array after deletion
    cout << "Array after deletion: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " " ;
    return 0;
}
