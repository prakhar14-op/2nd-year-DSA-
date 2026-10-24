#include<iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void bis(double a,double b ){
    if(f(a)*f(b)>0){
        cout<<"invlaid hai bidu";
        return;
    }

    double c=a;
    int decimal_places;
    cout << "kitne decimal place tak cahhiye bhaii ";
    cin >> decimal_places;
    double tol = 1.00 / pow(10, decimal_places);
    while((b-a)>=tol){
        c=(a+b)/2;
        if(f(c)==0){
            cout<<"root is :"<<c<<endl;
            break;
        }

        if(f(a)*f(c)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    cout<<"approximate :"<<c<<endl;


}
int main() {
    double a, b;
    int places;

    cout << "Enter interval [a, b]: ";
    cin >> a >> b;



    bis(a, b);

    return 0;
}