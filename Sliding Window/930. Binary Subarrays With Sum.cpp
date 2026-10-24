#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(vector<int>& nums,int goal){
        int l=0;
        int r=0;
        if(goal<0){
            return 0;
        }
        int sum=0;
        int count=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count+=r-l+1;
            r=r+1;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1=solve(nums,goal);
        int count2=solve(nums,goal-1);
        return count1-count2;
    }
};