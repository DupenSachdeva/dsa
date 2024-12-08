// derived from subset sum just target = sum/2

#include<iostream>
#include<vector>

using namespace std;
int subsetSum(vector<int> &arr,int n,int target){
     
     vector<vector<int>> dp(n+1,vector<int>(target+1,0));
     for(int i=0;i<=n;i++)
     dp[i][0] =1;

     for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){

            int take = 0;
            if(j-arr[i-1]>=0)
                take = dp[i-1][j-arr[i-1]];

            int nontake = dp[i-1][j];

            dp[i][j] = take + nontake;
        }

     }

     return dp[n][target];
     
}
int main(){
   
    vector<int> arr = {5,3,6,2,};
    int sum = 0;
    for(auto it:arr)
    sum += it;

    if(sum%2==1)
      cout<<"no equal subsets possible";

    else{
        cout<<"subsets count"<<subsetSum(arr,arr.size(),sum/2);
    }
    return 0;
}