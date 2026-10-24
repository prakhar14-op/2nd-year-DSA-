#include<iostream>
using namespace std;
int main(){
    int A[5];
    int b[5]={1,2,3,4,5};
    int c[10]={1,2,3};
    int d[5]={0};
    int e[]={1,2,3,4,5,6,7,8};
    for(int i=0;i<5;i++){
        cout<<"%u \n"<<&b[i];
    }  
}
