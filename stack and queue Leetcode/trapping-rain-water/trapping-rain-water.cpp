#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        //finding the prefix array to get the leftmax
        int n=height.size();
        int total=0;
        vector<int> prefixmax(n,0);
        prefixmax[0]=height[0];
        for(int i=1;i<n;i++){
            prefixmax[i]=max(prefixmax[i-1],height[i]);
        }
        vector<int> smax(n,0);
        smax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            smax[i]=max(smax[i+1],height[i]);
        }

        for(int i=0;i<n;i++){
            int leftmax=prefixmax[i];
            int rightmax=smax[i];
            if(height[i]<leftmax && height[i]<rightmax){
                total+=min(leftmax,rightmax)-height[i];
            }
        }
        return total;

    }
};
//OPTIMAL SOLUTION

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        //optimal
        int lmax=0;
        int rmax=0;
        int total=0;
        int l=0;
        int r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    total+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                }
                l=l+1;
            }
            else{
                if(rmax>height[r]){
                    total+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                }
                r=r-1;
            }
        }
        return total;
    }
};