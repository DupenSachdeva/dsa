#include<iostream>
#include<vector>

using namespace std;

bool checkSubsetSumTopDown(vector<int> &arr,int target,int n){

    vector<vector<int>> dp(n+1,vector<int>(target+1,false));

    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){

            int take = false;
            if(j-arr[i-1]>=0)
              take = checkSubsetSumTopDown(arr,target-arr[i-1],i-1);

            int nontake = checkSubsetSumTopDown(arr,j,i-1);

            dp[i][j] = take | nontake ;
        }
    }

    return dp[n][target];
}
int main(){
    
    vector<int> arr = {3,5,10};
    int target = 6;

    cout<<"result is "<< checkSubsetSumTopDown(arr,target,arr.size());
    return 0;
}