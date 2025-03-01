// find sum of all subtrees and print

#include<iostream>
#include<vector>

using namespace std;

int sum(int node , vector<vector<int>> &adj , int parent){

    int childrenSum = 0;

    for(auto it:adj[node]){

        if(it!=parent){
            childrenSum += sum(it,adj,node); 
        }
    }
    cout << " for node " << node << "sum is " << node + childrenSum;
    return node + childrenSum;


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

    vector<vector<int>> adj(n);

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    cout << sum(1,adj,-1);

    return 0;
}