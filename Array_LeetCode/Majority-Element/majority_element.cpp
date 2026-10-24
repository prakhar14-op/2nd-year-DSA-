#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
//method 1
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    count++;
                }
            }
            if(count>(n/2)){
                return nums[i];
            }
        }
        return -1;
    }

//method 2
    int majorityElement_1(vector<int>& nums){
        int n=nums.size();
        map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        //traversing in heap_map
        for(auto it:mp){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};