// to alocate array in heap 
#include<iostream>
using namespace std;
int main(){
    int A[5]={1,2,3,4,5};
    int *p;
    p= new int[5];
    p[0]=10;
    p[1]=11;
    p[2]=12;
    p[3]=13;
    p[4]=14;

    for (int i =0;i<5;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for (int i =0;i<5;i++){
        cout<<p[i]<<" ";
    }
}