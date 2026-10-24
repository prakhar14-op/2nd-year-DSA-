#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.length();
        if (k >= num.length()) return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && (st.top()-'0')>(num[i]-'0') && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
                return "0";
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top()); //imp
            st.pop();
        }
        while(res.length()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()){
            return "0";
        }
        return res;
    }
};