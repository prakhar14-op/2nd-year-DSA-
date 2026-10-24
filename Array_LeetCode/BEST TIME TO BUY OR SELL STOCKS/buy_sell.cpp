#include<vector>
#include<iostream>
using namespace std;
//method 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_prof=0;
        
        for(int i=0;i<n;i++){
            int prof=0;
            for(int j=i;j<n;j++){
                if(prices[j]-prices[i]<=0){
                    continue;
                }
                else{
                    prof = max(prof, prices[j] - prices[i]);
                }
            }
            max_prof=max(max_prof,prof);
        }
        return max_prof;
    }
};

//method 2;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
