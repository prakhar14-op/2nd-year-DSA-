#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            int current=asteroids[i];
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                bool survived = true;
                while(!st.empty() && st.top() > 0){
                    if(abs(st.top())<abs(current)){
                        st.pop();
                    }
                    else if(abs(st.top())>abs(current)){
                        survived=false;
                        break;
                    }
                    else{
                        st.pop();
                        survived=false;
                        break;
                    }
                }
                if(survived){
                    st.push(current);
                }
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};