#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxf=0;
        int max_len=0;
        vector<int> hash(26,0);
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            if((r-l+1-maxf)>k){
                hash[s[l]-'A']--;
                l++;
            }
            
            max_len=max(max_len,(r-l+1));

            r++;
        }
        return max_len;
    }
};