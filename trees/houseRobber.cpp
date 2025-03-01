// find the maximum path sum going downward only from any node

#include<iostream>
#include<vector>

using namespace std;
 void maxSum(int node  , vector<vector<int>> &adj , vector<int> &value , int parent , vector<vector<int>> &dp){
    

    for(auto it:adj[node]){

        if(it!=parent){
            maxSum(it,adj,value,node,dp);
        }
    }
    
    //take
    dp[node][1] = value[node];
    for(auto it:adj[node]){
        if(it!=parent){
        dp[node][1] += dp[it][0];
    }
    }

    //nottake
    dp[node][0] = 0;
    for(auto it:adj[node]){
        if(it!=parent){
            dp[node][0] += max(dp[it][1] , dp[it][0]);
        }
    }


}
int main(){
    
    int n;

    cout<<"write no of nodes";
    cin>>n;
    
    vector<pair<int,int>> edges(n-1);
    cout<<"write n-1 edges";
    for(int i=0;i<n-1;i++){
        int node1;
        int node2;

        cin>>node1;
        cin>>node2;

        edges[i] = {node1,node2};
    }

    vector<int> value(n+1);
    cout<<"write values for each nodes";
    for(int i=1;i<=n;i++)
     cin>>value[i];

    vector<vector<int>> adj(n);
    
    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    int ans = -1e9;

    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    maxSum(1,adj,value,-1,dp);
    cout <<max(dp[1][0] , dp[1][1]); 

    return 0;
}