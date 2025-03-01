
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int minBuses(int node , vector<vector<int>> &adj , int parent,map<int,int> &value){

    int buses = 0;

    for(auto it:adj[node]){

        if(it!=parent){
            buses += minBuses(it,adj,node,value);
        }
    }

    if(value[node] == 0){
        return buses;
    }

    else{
        if(buses==0)
        return 1;

        return buses;
    }
}
int main(){
    
    int n;
    map<int,int> value;

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
    
    cout<<"write value of each node from 1 to n either 0 or 1";
    for(int i=1;i<=n;i++){
        int val;
        cin>>val;
        value[i] = val;
    }
    vector<vector<int>> adj(n);

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    cout << minBuses(1,adj,-1,value);

    return 0;
}