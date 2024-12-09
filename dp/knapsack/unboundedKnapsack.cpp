#include<iostream>
#include<vector>

using namespace std;

int unboundedKnapsack(vector<int> &weight,vector<int> &price,int bagWeight,int n){
          
          vector<vector<int>> dp(n+1,vector<int>(bagWeight+1,0));

          for(int i = 1;i<=n;i++){
            for(int j=1;j<=bagWeight;j++){

                int take = 0;
                if(j-weight[i-1]>=0)
                 take = price[i-1] + dp[i][j-weight[i-1]];

                int nontake = dp[i-1][j];

                dp[i][j] = max(take,nontake);
            }
          }

          return dp[n][bagWeight];
}
int main(){
    
    vector<int> weight = {6,3,6,2,4,4};
    vector<int> price = {7,3,5,1,2,5};
    
    int bagWeight = 10;

    cout<< "maximum value using unboundedd knapsack"<< unboundedKnapsack(weight,price,bagWeight,6);

    return 0;
}