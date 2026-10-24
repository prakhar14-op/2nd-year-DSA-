#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int row, int col,vector<vector<int>>& dp,vector<vector<char>>& matrix,int& maxside){
        //base case 
        //out of bound 
        int m=matrix.size();
        int n=matrix[0].size();
        if(row<0 ||row>=m || col<0 || col>=n){
            return 0;
        }
        if(matrix[row][col]=='0'){
            return dp[row][col]=0;
        }
        //if we reach to the top most row or the roght most col then the max area at that will be 1
        if(row==0 || col==0){
            int val=matrix[row][col]-'0';
            maxside=max(maxside,val);
            return matrix[row][col]-'0';
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        //doing the top down thing 
        int up=solve(row-1,col,dp,matrix,maxside);
        int left=solve(row,col-1,dp,matrix,maxside);
        int d=solve(row-1,col-1,dp,matrix,maxside);
        dp[row][col]=min({up,left,d})+1;
        maxside=max(maxside,dp[row][col]);

        return dp[row][col];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] will contain the max area of the sqaure till the i, j index 
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int maxside=0;
        solve(m-1, n-1, dp, matrix, maxside);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1' && dp[i][j] == -1) {
                    solve(i, j, dp, matrix, maxside);
                }
            }
        }
        return maxside*maxside;
    }
};