#include<iostream>
using namespace std;
class solution {
    public:
    bool isPrime(int n){
        char p =true;
                
        if(n==1){
            p=false;

        }
        else{
            for(int i=2; i<=n/2;i++){
                if(n%i==0){
                    p=false;
                    cout<<"prime";
                    break;
                }
            }
        }
    }
};

int main(){
    solution s;
    int ans=s.isPrime(10);
    cout<<ans;
}
