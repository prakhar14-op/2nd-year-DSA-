#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int len=b.size();
        int i=1;
        int pow=b[0];
        while(i<len){
            pow*=10;
            pow+=b[i];
            i++;
        }
        cout<<b;
    }
};

int main(){
    vector<int> b={1,0};
    superPow(2,b);
}