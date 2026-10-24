#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    // 1. Input Array Elements 
    cout << "Enter " << size << " elements IN SORTED (ascending) ORDER:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // 2. Get the Element to Search 
    int key; // 'key' is the number we are looking for
    cout << "\nEnter the element (key) to search for: ";
    cin >> key;

    // 3. Binary Search Logic 
    int low = 0;
    int high = size - 1;
    int mid;
    bool found = false;
    int location = -1; // We'll store the index here if found
    while (low <= high) {
        // Find the middle index
        mid = (low + high) / 2;

        // Case 1: The element is at the middle
        if (arr[mid] == key) {
            found = true;
            location = mid;
            break; // Stop the loop, we found it!
        }
        // Case 2: The key is *greater* than the middle
 else if (key > arr[mid]) {
 low = mid + 1; // Move the 'low' pointer up
 }
 // Case 3: The key is *smaller* than the middle
 else { // (key < arr[mid])
 high = mid - 1; // Move the 'high' pointer down
 }
 }
 // 4. Display the Result 
 cout << "\n Binary Search Result " << endl;
 if (found == true) {
 cout << "Element " << key << " was found at index: " << location << endl;
 } else {
 cout << "Element " << key << " was NOT found in the array." << endl;
 }
 return 0;
}