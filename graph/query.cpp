#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

vector<int> find(int n ,vector<pair<int,int>> &edges , vector<pair<int,int>> &queries){
          
    vector<vector<int>> adj(n);

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first); 
    }

    map<int,int> nodeToCompo;

    int compoNo = 1;

    vector<int> visited(n,0);

    for(int i=0;i<n;i++){

        if(!visited[i]){
            dfs()
        }
    }

}
int main(){
   
    int n;
    cout<<"write no of nodes";
    cin>>n;

    int m;
    cout<<"write no of edges";
    cin>>m;
    
    cout<<"write edges";
    vector<pair<int,int>> edges;
    for(int i=1;i<=m;i++){
        int no1,no2;
        cin>>no1;
        cin>>no2;

        edges.push_back({no1,no2});
    }

    vector<pair<int,int>> queries;
    cout<<"write queries no";
    int q1;
    cin>>q1;

    cout<<"write queries";
    for(int i=1;i<=q1;i++){
        int t,n;
        cin>>t;
        cin>>n;

        queries.push_back({t,n});
    }


    vector<int> ans = find(n,edges,queries);

    for(int i=0;i<ans.size();i++){

        cout<<"ans for "<< i <<"query is " << ans[i]<<endl;
    }




    return 0;
}