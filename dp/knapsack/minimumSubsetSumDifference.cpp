#include<iostream>
#include<vector>

using namespace std;

pair<int,int> subsetSum(vector<int> &arr,int target,int n){

    vector<vector<int>> dp(n+1,vector<int>(target+1,0));

    for(int i=0;i<=n;i++)
    dp[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){

            int take = 0;
            if(j-arr[i-1]>=0)
               take = dp[i-1][j-arr[i-1]];

            int nontake = dp[i-1][j];

            dp[i][j] = take + nontake;
        }
    }
    
    int sum = 0;
    for(auto it:arr)
    sum+=it;

    for(int i=target;i>=1;i--){
        if(dp[n][i]>0)
          return {abs((sum-i)-i),dp[n][i]}; 
    }

    return {-1,-1};
}
int main(){

    vector<int> arr = {4,2,7,2,5,9};
    int sum = 0;

    for(auto it:arr)
    sum+=it;

    pair<int,int> ans = subsetSum(arr,sum/2,arr.size());

    cout<<"hi";
    cout<< "minimum subset sum difference is "<<ans.first<<"ans no. of subsets are"<<ans.second;

    return 0;
}