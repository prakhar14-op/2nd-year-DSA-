#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size (capacity) of the queues: ";
    cin >> size;
    cout << "\n\n PART 1: LINEAR QUEUE " << endl;
    
    int linear_queue[size];
    int front = -1; // 'front' tracks the index of the first element
    int rear = -1;  // 'rear' tracks the index of the last element

    //  Enqueue (Insert) Operation 
    cout << "\n Enqueue (Insert) " << endl;
    cout << "Enqueuing 3 elements: 10, 20, 30" << endl;
    
    // Enqueue 10
    if (rear == size - 1) {
        cout << "Queue is Full!" << endl;
    } else {
        if (front == -1) // First element
            front = 0;
        rear++;
        linear_queue[rear] = 10;
    }

    // Enqueue 20
    if (rear == size - 1) {
        cout << "Queue is Full!" << endl;
    } else {
        rear++;
        linear_queue[rear] = 20;
    }

    // Enqueue 30
    if (rear == size - 1) {
    cout << "Queue is Full!" << endl;
    } else {
    rear++;
    linear_queue[rear] = 30;
    }
    // Display Operation 
    cout << "\n Display" << endl;
    if (front == -1 || front > rear) {
    cout << "Queue is empty." << endl;
    } else {
    cout << "Queue elements (front to rear): ";
    for (int i = front; i <= rear; i++) {
    cout << linear_queue[i] << " ";
    }
    cout << endl;
    cout << "(front is at index " << front << ", rear is at index " << rear << ")" << endl;
    }
    //  Dequeue (Delete) Operation 
    cout << "\n Dequeue (Delete) " << endl;
    cout << "Dequeuing 2 elements" << endl;
    // Dequeue first element
    if (front == -1 || front > rear) {
    cout << "Queue is Empty!" << endl;
    } else {
    cout << "Dequeued element: " << linear_queue[front] << endl;
    front++; // This is the key part: 'front' just moves
    }
    // Dequeue second element
    if (front == -1 || front > rear) {
    cout << "Queue is Empty!" << endl;
    } else {
    cout << "Dequeued element: " << linear_queue[front] << endl;
    front++;
    }
    cout << "Queue after dequeuing (front to rear): ";
    for (int i = front; i <= rear; i++) {
    cout << linear_queue[i] << " ";
    }
    cout << endl;
    
    cout << "(front is now at index " << front << ", rear is at index " << rear << ")" << endl;
    // //  The PROBLEM with Linear Queues ---
    // cout << "\n The PROBLEM" << endl;
    // cout << "Trying to enqueue element 40" << endl;
    
    // Check if queue is full
    if (rear == size - 1) {
    cout << "Queue Overflow! Cannot enqueue." << endl;
    cout << "REASON: 'rear' is at the end of the array (index " << rear << ")." << endl;
    cout << "Even though we have empty space at the front (index 0, 1), the linear queue can't use it." << endl;
    // 
    } else {
    // This part won't run if the array is full
    rear++;
    linear_queue[rear] = 40;
    cout << "Enqueued 40." << endl;
    }

    // PART 2: CIRCULAR QUEUE (with the solution)
    cout << "\n\n PART 2: CIRCULAR QUEUE " << endl;
    cout << "(Solves the wasted space problem by 'wrapping around')\n" << endl;
    int c_queue[size];
    int c_front = -1;
    int c_rear = -1;
    
    cout << "Enqueuing 3 elements: 10, 20, 30" << endl;
    
    
    c_rear = (c_rear + 1) % size; c_queue[c_rear] = 10; c_front = 0;
    c_rear = (c_rear + 1) % size; c_queue[c_rear] = 20;
    c_rear = (c_rear + 1) % size; c_queue[c_rear] = 30;
    cout << "Queue (front to rear): ";
    for (int i = c_front; i != c_rear; i = (i + 1) % size) {
    cout << c_queue[i] << " ";
    }
    cout << c_queue[c_rear] << endl;
    cout << "(c_front is at " << c_front << ", c_rear is at " << c_rear << ")" << endl;
    //  Dequeue (Delete) Operation 
    cout << "\nDequeuing 2 elements..." << endl;
    
     // Dequeue 10
    cout << "Dequeued element: " << c_queue[c_front] << endl;
    if (c_front == c_rear) { c_front = -1; c_rear = -1; } // empty
    else { c_front = (c_front + 1) % size; }
    // Dequeue 20
    cout << "Dequeued element: " << c_queue[c_front] << endl;
    if (c_front == c_rear) { c_front = -1; c_rear = -1; } // empty
    else { c_front = (c_front + 1) % size; }
    cout << "(c_front is now at " << c_front << ", c_rear is at " << c_rear << ")" << endl;
    //  The SOLUTION with Circular Queues 
    cout << "\n The SOLUTION " << endl;
    cout << "Now, 'front' is at index 2, 'rear' is at index 2." << endl;
    cout << "Trying to enqueue element 40..." << endl;
    
    // Check if queue is full
    if ((c_rear + 1) % size == c_front) {
    cout << "Circular Queue is Full!" << endl;
    } else {
    
    c_rear = (c_rear + 1) % size; 
    c_queue[c_rear] = 40;
    cout << "Enqueued 40." << endl;
    }
    
    cout << "Trying to enqueue element 50..." << endl;
    if ((c_rear + 1) % size == c_front) {
    cout << "Circular Queue is Full!" << endl;
    } else {
    
    c_rear = (c_rear + 1) % size; 
    c_queue[c_rear] = 50;
    cout << "Enqueued 50." << endl;
    }
    
    cout << "Trying to enqueue element 60..." << endl;
    if ((c_rear + 1) % size == c_front) {
    cout << "Circular Queue is Full!" << endl;
    } else {
    
    c_rear = (c_rear + 1) % size; 
    c_queue[c_rear] = 60;
    cout << "Enqueued 60." << endl;
    }
    
     // Final Display (Circular)
    cout << "\n Final Display (Circular) " << endl;
    cout << "(c_front is at " << c_front << ", c_rear is at " << c_rear << ")" << endl;
    cout << "Queue elements (front to rear): ";
    if (c_front == -1) {
    cout << "Queue is empty." << endl;
    } 
    
    else {
    int i = c_front;
    while (true) {
    cout << c_queue[i] << " ";
    if (i == c_rear) // Stop after printing the 'rear' element
    break;
    i = (i + 1) % size; // Move to the next index, wrapping around
    }
    cout << endl;
    }
    
    return 0;
}