#include<iostream>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

void maxSum(int node , vector<vector<int>> &adj,vector<int> &value , int parent , vector<vector<int>> &dp){

    bool hasChildren = false;
    for(auto it:adj[node]){

        if(it!=parent){
        hasChildren = true;
        maxSum(it,adj,value,node,dp);
    }
    }

    if(!hasChildren){
        
        dp[node][1] = value[node];
        dp[node][0] = 0;
        dp[node][2] = 0;
    
    }

    else{
        
        int sumOfDpChildren0 = 0;
        int sumOfDpChildren1 = 0;
        int sumOfDpChildren2 = 0;


       for(auto it:adj[node]){

        if(it!=parent){

            sumOfDpChildren0 += dp[it][0];
            sumOfDpChildren1 += dp[it][1];
            sumOfDpChildren2 += dp[it][2];
        }
       }

       dp[node][1] = value[node] + sumOfDpChildren2;

       
       dp[node][2] = sumOfDpChildren0;


      // for  dp[node][0] two cases  1)-> take any one of the children ,
      // 2) dont take any children , thst is dp[c1][0] + dp[c2][0]+ ....dp[cn][0] == dp[node][2]


      int case1 = -1e9;

      for(auto it:adj[node]){

        if(it!=parent){

            case1 = max(case1 , dp[it][1] + sumOfDpChildren0 - dp[it][0]);
        }
      }


    int   case2 = dp[node][2];

      dp[node][0] = max(case1,case2);


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

    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    maxSum(1,adj,value,-1,dp);
    cout << max ( dp[1][0] , max(dp[1][1] , dp[1][2]  ) ); 

    return 0;
}