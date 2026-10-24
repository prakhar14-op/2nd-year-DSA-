#include <iostream>
using namespace std;

// --- 1. The 'merge' Function ---
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
  
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int Left[n1], Right[n2];

    // Copy data to the temporary Left[] and Right[] arrays
    for (i = 0; i < n1; i++) {
        Left[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        Right[j] = arr[mid + 1 + j];
    }

    //  The Merge Logic 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of the main (merged) array

    // Loop while we still have elements in *both* temp arrays
    while (i < n1 && j < n2) {
        // Compare the elements and copy the *smaller* one
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
 }
 // Copy any leftover elements 
 // If we ran out of 'Right' elements, copy the rest of 'Left'
 while (i < n1) {
 arr[k] = Left[i];
 i++;
 k++;
 }
 
 // If we ran out of 'Left' elements, copy the rest of 'Right'
 while (j < n2) {
 arr[k] = Right[j];
 j++;
 k++;
 }
}
//  2. The 'mergeSort' Function (Recursive) 
// This function recursively divides the array into two halves.
void mergeSort(int arr[], int low, int high) {
 // Base case: If low >= high, the array has 0 or 1 elements,
 // which is already sorted.
 if (low < high) {
 // 1. Find the middle point
 int mid = (low + high) / 2;
 // 2. "Divide"
 // Call mergeSort for the first half
 mergeSort(arr, low, mid);
 // Call mergeSort for the second half
 mergeSort(arr, mid + 1, high);
 // 3. "Conquer"
 // Merge the two sorted halves
 merge(arr, low, mid, high);
 }
}
int main() {
 int size;
 cout << "Enter the size of the array: ";
 cin >> size;
 int arr[size];
 // 1. Input Array Elements 
 cout << "Enter " << size << " elements (in any order):" << endl;
 for (int i = 0; i < size; i++) {
 cin >> arr[i];
 }
 // 2. Display Unsorted Array
 cout << "\n Unsorted Array" << endl;
 for (int i = 0; i < size; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 // 3. Call Merge Sort 
 // We make the first call on the entire array
 mergeSort(arr, 0, size - 1);
 // 4. Display Sorted Array
 cout << "\n Array after Merge Sort " << endl;
 for (int i = 0; i < size; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 return 0;
}