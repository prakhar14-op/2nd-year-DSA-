#include<iostream>
using namespace std;
int main(){
    int *p;
    p= new int[5];
    p[0]=10;
    p[1]=11;
    p[2]=12;
    p[3]=13;
    p[4]=14;

    int *q= new int[10];
    for (int i=0;i<5;i++){
        q[i]=p[i];
    }

    delete []p;

    p=q;

    q=NULL;
}