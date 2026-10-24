#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,list<pair<int,int>>> adj;
    //adding the edges to the adjacency list
    void addedge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //creating the adj 
        adj.clear();
        for(auto it:times){
            addedge(it[0],it[1],it[2]);
        }

        //applying the diijkstra
        //source node =k
        vector<int> time(n+1,1e9);
        set<pair<int,int>> st; //{time,node}
        time[k]=0;
        st.insert({0,k});

        while(!st.empty()){
            auto top=*(st.begin());
            int top_time=top.first;
            int top_node=top.second;
            st.erase(st.begin());

            //ab yha se neighbour vla traversing
            for(auto it:adj[top_node]){
                if(top_time+it.second<time[it.first]){
                    //checking kya vo phle se to nhi hai set me 
                    auto record=st.find({time[it.first],it.first});
                    if(record!=st.end()){
                        st.erase(record);
                    }
                    //now updation part
                    time[it.first]=top_time+it.second;
                    st.insert({time[it.first],it.first});
                }
            }
        }
        //checking if any entry is 1e9 in time then return -1
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9){
                return -1;
            }
        }
        //now returing the max value form our time vector
        //To get the maximum value, you must dereference it using the asterisk operator (*).
        //Since node 0 is unused in a 1-based setup, start searching from index 1.
        int ans=*max_element(time.begin()+1,time.end());
        return ans;

    }
};