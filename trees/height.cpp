// i will get tree in form of edges

#include<iostream>
#include<vector>

using namespace std;

int height(int node , vector<vector<int>> &adj , int parent){

    int maxChildrenHeight = 0;

    for(auto it:adj[node]){

        if(it!=parent){
            maxChildrenHeight = max(maxChildrenHeight , height(it,adj,node));
        }
    }

    return 1 + maxChildrenHeight;


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

    cout << height(1,adj,-1);

    return 0;
}