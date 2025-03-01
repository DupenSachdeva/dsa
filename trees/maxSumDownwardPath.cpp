// find the maximum path sum going downward only from any node

#include<iostream>
#include<vector>

using namespace std;

int maxPathSum(int node , vector<vector<int>> &adj , vector<int> &value , int parent,int &ans){

    int maxSumChildren = -1e9;

    for(auto it:adj[node]){

        if(it!=parent){
            maxSumChildren = max(maxSumChildren , maxPathSum(it,adj,value,node,ans));
        }
    }
    
    int maxDownwardPathFromCurNode = -1e9;

    maxDownwardPathFromCurNode = max(value[node] , value[node] + (maxSumChildren==-1e9 ? 0 : maxSumChildren));
    

    return maxDownwardPathFromCurNode;
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
    maxPathSum(1,adj,value,-1,ans);
    cout <<ans; 

    return 0;
}