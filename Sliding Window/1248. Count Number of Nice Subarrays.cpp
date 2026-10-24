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
    int numberOfSubarrays(vector<int>& nums, int k) {
        //converting the nums 
        //odd number will be rep as 1 
        // even number will be rep as 0
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        int count1=solve(nums,k);
        int count2=solve(nums,k-1);
        return count1-count2;

    }
};