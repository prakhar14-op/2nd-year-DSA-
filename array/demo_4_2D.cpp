#include<iostream>
using namespace std;
int main(){
    // method 1 
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout<<"A IS :"<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    //method 2
    int *b[3];
    b[0]=new int[4];
    b[1]=new int[4];
    b[2]=new int[4];

    b[0][0]=1;
    b[0][1]=2;
    b[0][2]=3;
    b[0][3]=4;
    b[1][0]=5;
    b[1][1]=6;
    b[1][2]=7;
    b[1][3]=8;
    b[2][0]=9;
    b[2][1]=10;
    b[2][2]=11;
    b[2][3]=12;

    cout<<"B IS:";
    cout<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    //method 3 
    int **c;
    c=new int*[3];
    c[0]=new int[4];
    c[1]=new int[4];
    c[2]=new int[4];

}