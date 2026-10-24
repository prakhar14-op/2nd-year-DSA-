#include<iostream>
#include<algorithm>
using namespace std;
int max(int a, int b, int c){
    // int num[3] = {a, b, c};
    // sort(num,num+3);
    // return num[2];
    return max({a,b,c});
}

int main(){
    int m=max(7,10,5);
    cout<<m;
    
}