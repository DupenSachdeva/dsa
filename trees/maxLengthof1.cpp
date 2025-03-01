#include<bits/stdc++.h>

using namespace std;

int dfs(int node , int par , vector<vector<int>> &adj , int &ans,vector<int> &value,vector<int> &dp , vector<int> &ansdp){

    
    for(auto it:adj[node]){

        if(it == par)
        continue;
        
        dfs(it,node,adj,ans,value,dp,ansdp);


    }
    
    if(value[node] == 0){
        dp[node] = 0;
        ansdp[node] = 0;
    }
    
    int maxchild1  = 0;
    int maxchild2 = 0;

    for(auto it:adj[node]){
        if(it==par)
        continue;

        if(dp[it] >= maxchild1){
            maxchild2 = maxchild1;
            maxchild1 = dp[it];
        }

        else{
            if(dp[it] < maxchild1 && dp[it]>maxchild2)
            maxchild2 = dp[it];
        }
    }

    dp[node] = maxchild1;
    ansdp[node] = 1 + maxchild1 + maxchild2;

    ans = max(ans , ansdp[node]);
}
int main(){

    int n;

    vector<int> value(n);

    cout<<"write no of nodes";
    cin>>n;
    
    cout<<"write value";
    for(int i=0;i<n;i++)
    cin>>value[i];

    cout<<"write edges";
    vector<pair<int,int>> edges;
    for(int i=1;i<=n-1;i++){
        int no1,no2;
        cin>>no1;
        cin>>no2;

        edges.push_back({no1,no2});
    }

    vector<vector<int>> adj(n);

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    
    int ans = 0;
    vector<int> dp(n);
    vector<int> ansdp(n);
     dfs(0,-1,adj,ans,value,dp,ansdp);

     cout<<"ans is "<< ans;
}