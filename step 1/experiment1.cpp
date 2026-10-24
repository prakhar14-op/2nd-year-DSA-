// #include<iostream>
// using namespace std;
// int main(){
//     // making an array 
//     int arr[100];
//     int n ;

//     cout<<"enter the number of elemnt in array ";
//     cin>>n;

//     // taking elments from the user 
//     for (int i=0;i<n; i++){
//         cout<<"enter the element of the array ";
//         cin>>arr[i];

//     }
//     // printing the array 
//     for(int j = 0; j<n;j++){
//         cout<<arr[j]<<" ";

//     }
//     // inserting tement in an array 
//     int current_size=n;
//     int updated_size=n+1;
//     arr[current_size]=arr[updated_size];
//     int ele;
//     cout<<"\n enter the elemnt you want to add ";
//     cin>> ele;
//     arr[n]=ele;
//     cout<<"elmenet adding is ";
//     cout<<arr[n];
//     for(int j = 0; j<n+1;j++){
//         cout<<arr[j]<<" ";

//     }
     
//     // deleting the elemnet
//     int deletion_index;
//     cout<<"enter the elment you want to delete";
//     cin>>deletion_index;
//     for(int i=0;i<deletion_index-1;i++){
//         arr[deletion_index]=arr[deletion_index-1];
//     }

//         for(int j = 0; j<n+1;j++){
//         cout<<arr[j]<<" ";

//     }
// }


#include<iostream>
using namespace std;

struct myarray{
    int *p;
    int size;
};
// struct array *arr1;
// struct array *arr2;

void display(int *a, int size){
    for(int i =0;i<size;i++){
        cout<<a[i]<<" ";
    }
}
struct myarray *arr2 =new myarray;

void insert(struct myarray *a,int index,int key){
    //checking the index is valid or not 
    if(index<0 || index>a->size){
        cout<<"index is invalid";
        return;
    }
    arr2->size = a->size + 1;
    arr2->p = new int[arr2->size];
    
    for (int i = 0; i < index; i++){
        arr2 -> p[i] = a -> p[i];
    }
    arr2 -> p[index] = key;
    for (int i = index + 1; i< arr2 -> size; i++){
        arr2 -> p[i] = a -> p[i-1];
    }
    
}

int main(){
    struct myarray *ptr=new myarray;
    cout<<"enter the size of the array ";
    cin>>ptr->size;

    // making a pointer in heap which will point to our array
    ptr->p=new int[ptr->size];

    // taking inputs
    for(int i=0;i<ptr->size;i++){
        cin>>ptr->p[i];
    }
    insert(ptr,2,100);

    display(ptr->p,ptr->size);

}