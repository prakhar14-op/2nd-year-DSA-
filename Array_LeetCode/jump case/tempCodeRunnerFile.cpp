#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check_jump_last(vector<int> nums){
    int n=nums.size();  //length of the array which we will use to iterate to the last index 
    int i=0;
    while(i<=n){
        if(nums[i]==nums[n-1]){
            return true;
        }
        i=i+nums[i];
        
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector <int> nums={2,3,1,2,4};
    if(check_jump_last(nums)){
        cout<<"reached the last position";
    }
    else{
        cout<<"sorryyyyyy bhai";
    }
}
